class Solution {
    int di[4] = { 0, 1, -1, 0 };
    int dj[4] = { 1, 0, 0, -1 };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = 0;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    vis[i][j] = true;
                    while (!st.empty()) {
                        auto p = st.top(); st.pop();
                        ++cnt;
                        for (int k = 0; k < 4; ++k) {
                            int ii = p.first + di[k];
                            int jj = p.second + dj[k];
                            if (ii >= 0 && ii < n && jj >= 0 
                                && jj < m && grid[ii][jj] == 1 && !vis[ii][jj]) {
                                st.push({ii, jj});
                                vis[ii][jj] = true;
                            }
                        }
                    }
                    ans = max(cnt, ans);
                }
            }
        }
        return ans;
    }
};
