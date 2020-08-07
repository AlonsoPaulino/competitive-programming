class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for (auto c: s) {
            if (c >= '0' && c <= '9') x += c;
            if (c >= 'a' && c <= 'z') x += tolower(c);
            if (c >= 'A' && c <= 'Z') x += tolower(c);
        }
        cout << x << endl;
        int n = (int) x.size();
        for (int i = 0; i < n / 2; ++i) {
            if (x[i] != x[n - i - 1]) return false;
        }
        return true;
    }
};