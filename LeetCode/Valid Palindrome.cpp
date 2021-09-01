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

// Another solution written on 08/31/2021
class Solution {
public:
    bool is_valid(char c) {
        return is_number(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    bool is_number(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool isPalindrome(string s) {
        int n = (int) s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !is_valid(s[i])) ++i;
            while (j >= 0 && !is_valid(s[j])) --j;
            if (i < j && i < n && j >= 0) {
                if (is_number(s[i])) {
                    if (s[i] != s[j]) return false;
                } else {
                    if (tolower(s[i]) != tolower(s[j])) return false;
                }
            }
            i = i + 1; j = j - 1;
        }
        return true;
    }
};
