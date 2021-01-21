class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto x: s) {
            if (x == '(' || x == '{' || x == '[') ss.push(x);
            else {
                if (ss.empty()) {
                    return false;
                }
                char c = ss.top(); ss.pop();
                if ((c == '(' && x != ')') || (c == '{' && x != '}') || (c == '[' && x != ']')) {
                    return false;
                }
            }
        }
        return ss.empty();
    }
};

// Another solution written in 01/20/2021
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m['('] = ')', m['['] = ']', m['{'] = '}';
        stack<char> st;
        for (auto x: s) {
            if (m.find(x) != m.end()) {
                st.push(x);
            } else {
                if (st.empty()) return false;
                char c = st.top(); st.pop();
                if (m[c] != x) return false;
            }
        }
        return st.empty();
    }
};
