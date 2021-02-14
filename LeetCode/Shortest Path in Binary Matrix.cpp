class Solution {
    const int INF = 1e9;
    int di[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
    int dj[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = n == 0 ? 0 : (int) grid[0].size();
        if (n == 0) return -1;
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        grid[0][0] = 1;
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            
            for (int k = 0; k < 8; ++k) {
                int ii = u.first + di[k], jj = u.second + dj[k];
                if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] == 0) {
                    q.push({ii, jj});
                    grid[ii][jj] = grid[u.first][u.second] + 1;
                }
            }
        }
        
        if (grid[n - 1][m - 1] == 0) return -1;
        return grid[n - 1][m - 1];
    }
};
