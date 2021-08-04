class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = (int) mat1.size();
        int m = (int) mat1[0].size();
        int p = (int) mat2[0].size();
        
        vector<vector<int>> ans(n, vector<int>(p, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                int res = 0;
                for (int k = 0; k < m; ++k) {
                    res += (mat1[i][k] * mat2[k][j]);
                }
                ans[i][j] = res;
            }
        }
        
        return ans;
    }
};
