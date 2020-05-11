class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int dp[n + 5][n + 5];
        for (int i = 0; i < n; ++i) dp[i][i] = arr[i];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] ^ arr[j];
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int k = i + 1; k < n; ++k) {
                for (int j = i + 1; j <= k; ++j) {
                    if (dp[i][j - 1] == dp[j][k]) ans++;
                }   
            }
        }
        return ans;
    }
};