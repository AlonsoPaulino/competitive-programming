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

/* Another solution submitted by 12/29/2020 */
class Solution {
    int n, m;
public:
    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = (int) grid.size();
        if (n == 0) return 0;
        m = (int) grid[0].size();
        
        int ans = 0;
        int di[] = { 0, 0, 1, -1 };
        int dj[] = { 1, -1, 0, 0 };
        
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x = grid[i][j];
                if (!visit[i][j] && x == '1') {
                    ++ans;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    while (!st.empty()) {
                        auto u = st.top(); st.pop();
                        visit[u.first][u.second] = true;
                        
                        for (int k = 0; k < 4; ++k) {
                            int ii = u.first + di[k], jj = u.second + dj[k];
                            if (isValid(ii, jj) && grid[ii][jj] == '1' && !visit[ii][jj]) {
                                st.push({ii, jj});
                            }
                        }
                    }           
                }
            }
        }
        
        return ans;
    }
};