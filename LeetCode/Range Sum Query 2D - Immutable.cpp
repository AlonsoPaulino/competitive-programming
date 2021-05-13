class NumMatrix {
    int n = 0, m = 0;
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = (int) matrix.size();
        m = (int) matrix[0].size();
        v = vector<vector<int>>(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) v[i][0] = matrix[i][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                v[i][j] = v[i][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; ++i) {
            result += v[i][col2];
            if (col1 > 0) {
                result -= v[i][col1 - 1];
            }
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
