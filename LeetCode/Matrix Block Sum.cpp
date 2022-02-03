class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> r(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            r[i][0] = mat[i][0]; 
            for (int j = 1; j < m; ++j) {
                r[i][j] = r[i][j - 1] + mat[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int p = max(0, i - k); p <= min(n - 1, i + k); ++p) {
                    ans[i][j] += r[p][min(m - 1, j + k)];
                    int lo = j - k - 1;
                    if (lo >= 0) {
                        ans[i][j] -= r[p][lo];
                    }
                }    
            }
        }
        
        return ans;
    }
};
