class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        vector<int> v(n * n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) v[i * n + j] = matrix[i][j];
        
        int t = n * n, x = 0;
        
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                matrix[i][j] = v[x++];
                x %= t;
            }
        }
    }
};
