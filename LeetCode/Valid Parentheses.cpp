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