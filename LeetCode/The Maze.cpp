class Solution {
    vector<vector<int>> v;
    int n, m;
public:
    int isValid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = (int) maze.size(), m = n > 0 ? (int) maze[0].size() : 0, v = maze;
        int dx[] = { 0, 1, -1, 0 };
        int dy[] = { 1, 0, 0, -1 };
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u.first == destination[0] && u.second == destination[1]) {
                return true;
            }
            visit[u.first][u.second] = true;
            for (int k = 0; k < 4; ++k) {
                int dxk = dx[k], dyk = dy[k];
                int i = u.first, j = u.second;
                int ii = i + dxk, jj = j + dyk;
                while (isValid(ii, jj) && v[ii][jj] == 0) {
                    i = ii, j = jj;
                    ii += dxk, jj += dyk;
                }
                if (!visit[i][j]) {
                    q.push({i, j});
                }
            }
        }
        return false;
    }
};