class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = (int) s.size();
        
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            char x = s[i];
            if (x == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '.';
                }
            } else if (x == '(') {
                st.push(i);
            }
        }
        
        while (!st.empty()) {
            s[st.top()] = '.';
            st.pop();
        }
        
        string ans;
        
        for (int i = 0; i < n; ++i) if (s[i] != '.') ans += s[i];
        
        return ans;
    }
};
