class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int n = (int) s.size(), i = 1;
        while (i < n) {
            int a = i - 1, b = i;
            while (a >= 0 && s[a] == '0') --a;
            while (b < n && s[b] == '0') ++b;
            while (a >= 0 && b < n && s[a] == s[b]) {
                s[a] = s[b] = '0';
                while (a >= 0 && s[a] == '0') --a;
                while (b < n && s[b] == '0') ++b;
            }
            b == i ? ++i : i = b;
        }
        for (auto c: s) if (c != '0') ans += c;
        return ans;
    }
};
