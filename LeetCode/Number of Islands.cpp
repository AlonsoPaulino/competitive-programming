class Solution {
public: 
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int n, m;
    
    bool dfs(vector<vector<char>>& g, int x, int y) {
        if (g[x][y] != '1') return false;
        stack< pair<int, int> > s;
        s.push(make_pair(x, y));
        while (!s.empty()) {
            pair<int, int> p = s.top(); s.pop();
            g[p.first][p.second] = '2';
            for (int i = 0; i < 4; ++i) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '1') {
                    s.push(make_pair(nx, ny));
                }
            }
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = n > 0 ? grid[0].size() : 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool cnt = dfs(grid, i, j);
                if (cnt) ans++;
            }
        }
        return ans;
    }
};