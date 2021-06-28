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

// Another solution written at 06/28/2021
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        int x = (int) st.size();
        string ans = string(x, 'x');
        while (!st.empty()) {
            ans[--x] = st.top();
            st.pop();
        }
        return ans;
    }
};
