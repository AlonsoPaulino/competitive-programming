class Solution {
public:
    int n = 0;
    vector<vector<bool>> pal;
    map<int, int> memo;
    
    int dp(string& s, int i) {
        auto it = memo.find(i);
        if (it != memo.end()) {
            return it->second;
        }
        if (pal[i][n - 1]) {
            memo[i] = 0;
        } else {
            int res = n - i - 1;
            for (int j = i + 1; j < n; ++j) {
                if (pal[i][j - 1]) {
                    res = min(res, dp(s, j) + 1);
                }
            }
            memo[i] = res;
        }
        return memo[i];
    }
    
    int minCut(string s) {
        n = (int) s.size();
        pal = vector<vector<bool>>(n + 5 , vector<bool>(n + 5, false));
        for (int sz = 1; sz <= n; ++sz) {
            for (int i = 0; i + sz <= n; ++i) {
                int j = i + sz - 1;
                pal[i][j] = (s[i] == s[j]);
                if (sz > 2) {
                    pal[i][j] = pal[i][j] && pal[i + 1][j - 1];
                }
            }
        }
        
        return dp(s, 0);
    }
};
