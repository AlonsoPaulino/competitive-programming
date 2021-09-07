class Solution {
public:
    bool validPalindrome(string s) {
        int n = (int) s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return is_palindrome(s, i + 1, j) || is_palindrome(s, i, j - 1);
            }
            ++i, --j;
        }
        return true;
    }
    
    bool is_palindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i, --j;
        }
        return true;
    }
};
