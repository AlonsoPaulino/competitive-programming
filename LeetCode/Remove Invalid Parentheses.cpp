class Solution {
public:    
    vector<string> removeInvalidParentheses(string s) {
        int n = (int) s.size();
        int total = 1 << n;
        int min_del = INT_MAX;
        set<string> st;
        for (int mask = 0; mask < total; ++mask) {
            int x = mask;
            bool is_valid = true;
            for (int i = n - 1; i >= 0; --i) {
                if ((1 << i) & mask) {
                    if (s[i] != ')' && s[i] != '(') {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (!is_valid) {
                continue;
            }
            int cnt = 0, del = 0;
            for (int i = n - 1; i >= 0; --i) {
                if ((1 << i) & mask) {
                    ++del; continue;
                }
                if (s[i] == ')') {
                    ++cnt;
                } else if (s[i] == '(') {
                    if (cnt == 0) {
                        cnt = -1;
                        break;
                    }
                    cnt = cnt - 1;
                }
            }
            if (cnt == 0) {
                if (del < min_del) {
                    min_del = del;
                    st.clear();
                }
                if (del == min_del) {
                    string x = "";
                    for (int i = n - 1; i >= 0; --i) {
                        if ((1 << i) & mask) continue;
                        x += s[i];
                    }
                    st.insert(x);
                }
            }
        }
        vector<string> ans;
        for (auto x: st) {
            reverse(x.begin(), x.end());
            ans.push_back(x);
        }
        return ans;
    }
};
