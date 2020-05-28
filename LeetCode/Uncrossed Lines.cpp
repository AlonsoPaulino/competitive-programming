class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int a = 0, b = 0;
        int nA = (int) A.size(), nB = (int) B.size();
        vector<vector<int>> dp(nA + 5, vector<int>(nB + 5, 0));
        for (int i = 1; i <= nA; ++i) {
            for (int j = 1; j <= nB; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nA][nB];
    }
};