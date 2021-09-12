class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int) s.size();
        stack<int> left;
        int ans = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == ')') {
                if (!left.empty()) {
                    left.pop();
                    if (left.empty()) {
                        ans = max(ans, i - k + 1);
                    }
                } else {
                    k = i + 1;
                }
            }
        }
        int last = n - 1;
        while (!left.empty()) {
            int t = left.top();
            ans = max(ans, last - t);
            last = t - 1;
            left.pop();
        }
        return ans;
    }
};
