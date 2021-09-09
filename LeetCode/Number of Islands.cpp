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

// Another solution written on 08/31/2021
class Solution {
public:
    int n, m;
    vector<int> g;
    
    int di[4] = { -1, 1, 0, 0 };
    int dj[4] = { 0, 0, 1, -1 };
    
    int find(int x) {
        if (g[x] == x) return x;
        return g[x] = find(g[x]);
    }
    
    void join(int x, int y) {
        g[find(x)] = find(y);
    }
    
    int encode(int i, int j) {
        return i * m + j;
    }
    
    bool is_valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = (int) grid.size();
        m = (int) grid[0].size();
        g = vector<int>(n * m + 10, 0);
        for (int i = 0; i < n * m; ++i) g[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + di[k], nj = j + dj[k];
                        if (is_valid(ni, nj) && grid[ni][nj] == '1') {
                            join(encode(ni, nj), encode(i, j));
                        }
                    }   
                }
            }
        }
        set<int> st;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    st.insert(find(encode(i, j)));
                }
            }
        }
        return (int) st.size();
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = (int) grid.size();
        if (n == 0) return 0;
        int m = (int) grid[0].size();
        
        int di[4] = { -1, 1, 0, 0 };
        int dj[4] = { 0, 0, 1, -1 };
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {    
                char c = grid[i][j];
                if (c == '1') {
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    grid[i][j] = '0';
                    while (!st.empty()) {
                        auto p = st.top(); st.pop();
                        for (int k = 0; k < 4; ++k) {
                            int ii = p.first + di[k], jj = p.second + dj[k];
                            if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] == '1') {
                                grid[ii][jj] = '0';
                                st.push({ii, jj});
                            }
                        }
                    }
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
