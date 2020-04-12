class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> ss;
        stack<char> st;
        for (auto c: S) {
            if (c != '#') ss.push(c); else if (!ss.empty()) ss.pop();
        }
        for (auto c: T) {
            if (c != '#') st.push(c); else if (!st.empty()) st.pop();
        }
        if (ss.size() != st.size()) return false;
        while (!ss.empty() && ss.top() == st.top()) {
            ss.pop(), st.pop();
        }
        return ss.empty();
    }
};