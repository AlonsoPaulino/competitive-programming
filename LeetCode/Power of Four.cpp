class Solution {
public:
    bool isPowerOfFour(int num) {
        bool ans = false;
        int cnt = 0, i = 1;
        while (num > 0) {
            if (num & 1) cnt++, ans |= (i & 1);;
            if (cnt > 1) return false;
            num = num >> 1;
            ++i;
        }
        return ans;
    }
};