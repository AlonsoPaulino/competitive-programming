#define vvi vector<vector<int>> 
#define vi vector<int>
#define fi first
#define se second

const int di[4] = { 0, 0, -1, 1 };
const int dj[4] = { 1, -1, 0, 0 };

class Solution {
public:
    int bfs(vvi&g, int n, int m, int x, int y, int target) {
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int cnt = 0, res = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({ 0, { x, y } });
        visit[x][y] = true;
        
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int ii = node.se.fi + di[k], jj = node.se.se + dj[k];
                if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                    if (!visit[ii][jj]) {
                        if (g[ii][jj] == 0) {
                            q.push({ node.fi + 1, { ii, jj } });
                            visit[ii][jj] = true;
                        } else if (g[ii][jj] == 1) {
                            visit[ii][jj] = true;
                            res += node.fi + 1;
                            if (++cnt == target) {
                                return res;
                            }
                        }
                    }
                }
            }
        }
        if (cnt < target) return -1;
        return res;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        int ans = -1, target = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) target++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    int x = bfs(grid, n, m, i, j, target);
                    if (x == -1) continue;
                    ans = (ans == -1) ? x : min(ans, x);
                }
            }
        }
        return ans;
    }
};
