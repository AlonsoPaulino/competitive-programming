class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, n = (int) s.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                --cnt;
            }
            ans = max(cnt, ans);
        }
        
        return ans;
    }
};
