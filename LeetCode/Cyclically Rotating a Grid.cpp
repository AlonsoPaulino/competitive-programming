class Solution {
    int n, m;
public:
    pair<int, int> transform(int i, int j, int x, int k) {
        int ii = i, jj = j;
        int h = x + n - 2 * x, w = x + m - 2 * x;
        int total = 2 * ((n - 2 * x) + (m - 2 * x)) - 4;
        int kk = k % total;
        
        while (kk > 0) {
            if (jj == x) {
                ii < h - 1 ? ++ii : ++jj;
            } else if (jj == w - 1) {
                ii == x ? --jj : --ii;
            } else if (ii == x) {
                jj == x ? ++ii : --jj;
            } else if (ii == h - 1) {
                jj < w - 1 ? ++jj : --ii;
            }
            --kk;
        }
        
        return { ii, jj };
    }
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for (int x = 0; x < min(n, m) / 2; ++x) {
            for (int j = x; j < m - x; ++j) {
                auto r1 = transform(x, j, x, k);
                auto r2 = transform(n - x - 1, j, x, k);
                ans[r1.first][r1.second] = grid[x][j];
                ans[r2.first][r2.second] = grid[n - x - 1][j];
            }
            for (int i = x + 1; i < n - x - 1; ++i) {
                auto c1 = transform(i, x, x, k);
                auto c2 = transform(i, m - x - 1, x, k);
                ans[c1.first][c1.second] = grid[i][x];
                ans[c2.first][c2.second] = grid[i][m - x - 1];
            }
        }
        return ans;
    }
};
