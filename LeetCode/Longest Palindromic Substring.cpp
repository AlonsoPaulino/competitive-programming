class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        int ii = 0, jj = 0; 
        vector<vector<bool>> dp(n + 5, vector<bool>(n + 5, false));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (k == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if (dp[i][j]) {
                    ii = i, jj = j;
                }
            }
        }
        string ans = s.substr(ii, jj - ii + 1);
        return ans;
    }
};