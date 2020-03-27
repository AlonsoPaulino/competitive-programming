class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int ans = 0;
        int total = slices.size();
        int n = total/3;
        
        vector< vector<int> > dp1(total, vector<int>(n + 5, 0));
        vector< vector<int> > dp2(total, vector<int>(n + 5, 0));
        
        dp1[0][1] = slices[0];
        dp1[1][1] = max(dp1[0][1], slices[1]);
        
        dp2[0][1] = slices[total - 1];
        dp2[1][1] = max(slices[1], dp2[0][1]);
        dp2[1][2] = slices[total - 1] + slices[1];
        
        for (int i = 2; i < total - 1; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i < total - 2) {
                    dp2[i][j] = max(dp2[i - 1][j], dp2[i - 2][j - 1] + slices[i]);
                }
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 2][j - 1] + slices[i]);   
            }
        }
        
        for (int i = 0; i < total; ++i) {
            ans = max(ans, max(dp1[i][n], dp2[i][n]));
        }
        
        return ans;
    }
};