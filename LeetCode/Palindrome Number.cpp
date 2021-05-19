class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int n = log10(x) + 1, a = 0;
        for (int i = 0; i < n / 2; ++i) {
            a *= 10, a += (x % 10);
            x /= 10;
        }
        if (n & 1) x /= 10;
        return a == x;
    }
};
