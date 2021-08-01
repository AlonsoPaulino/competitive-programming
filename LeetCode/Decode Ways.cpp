class Solution {
public:
    unordered_map<int, int> memo;
    
    int f(int x) {
        auto it = memo.find(x);
        if (it != memo.end()) {
            return it->second;
        }
        if (x < 0) return 0;
        if (x == 0) return 1;
        int res = f(x - 1) + f(x - 2);
        memo[x] = res;
        return res;
    }
    
    int numDecodings(string s) {
        int ans = 1, n = (int) s.size();
        int group = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            if (x == 0 && (i == 0 || (s[i - 1] - '0') > 2)) {
                return 0;
            }
            if (x == 0) {
                ans *= f(group - 1);
                group = 0;
            } else if (x > 6 && i > 0 && (s[i - 1] - '0') > 1) {
                ans *= f(group);
                group = 1;
            } else if (i > 0 && (s[i - 1] - '0') > 2) {
                ans *= f(group);
                group = 1;
            } else {
                ++group;
            }
        }
        if (group > 0) {
            ans *= f(group);
        }
        return ans;
    }
};
