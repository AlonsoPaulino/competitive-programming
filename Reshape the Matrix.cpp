class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        if (n * m != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[k / c][k % c] = mat[i][j];
                ++k;
            }
        }
        return ans;
    }
};
