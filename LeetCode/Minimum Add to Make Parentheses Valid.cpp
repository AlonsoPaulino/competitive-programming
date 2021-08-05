class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int n = (int) s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    ++ans;
                }
            }
        }
        ans += (int) st.size();
        return ans;
    }
};
