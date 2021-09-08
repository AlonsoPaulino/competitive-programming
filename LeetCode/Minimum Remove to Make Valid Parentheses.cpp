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

// Another solution written on 08/26/2021
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> pos;
        int n = (int) s.size();
        stack<int> left;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == ')') {
                if (!left.empty()) {
                    left.pop();
                } else {
                    pos.push_back(i);
                }
            }
        }
        while (!left.empty()) {
            pos.push_back(left.top());
            left.pop();
        }
        sort(pos.begin(), pos.end());
        string ans = "";
        int m = (int) pos.size(), j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < m) {
                if (pos[j] == i) {
                    ++j;
                    continue;
                }
            }
            ans += s[i];
        }
        return ans;
    }
};

// Another solution written on 09/07/2021
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> tr;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    tr.push_back(i);
                } else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            tr.push_back(st.top());
            st.pop();
        }
        sort(tr.begin(), tr.end());
        string ans = "";
        
        int j = 0, m = (int) tr.size();
        for (int i = 0; i < n; ++i) {
            if (j < m && tr[j] == i) {
                ++j;
                continue;
            }
            ans += s[i];
        }
        
        return ans;
    }
};
