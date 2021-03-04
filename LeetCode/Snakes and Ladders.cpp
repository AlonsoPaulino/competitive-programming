class Solution {
    int n;
public:
    int get_val(int x, vector<vector<int>>& b) {
        int row = (x - 1) / n;
        int col = (x - 1) % n;
        int i = n - 1 - row, j = row & 1 ? n - 1 - col : col;
        return b[i][j];
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = (int) board.size();
        int total = n * n;
        
        unordered_map<int, bool> visit;
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        
        while (!q.empty()) {
            auto pp = q.front(); q.pop();
            
            int u = pp.first;
            int cnt = pp.second;
            
            if (u == total) return cnt;
            
            for (int j = 1; j <= 6 && pp.first + j <= total; ++j) {
                int v = u + j;
                int x = get_val(v, board);
             
                if (x == -1 && !visit[v]) {
                    if (v == total) return cnt + 1;
                    q.push({v, cnt + 1});
                    visit[v] = true;
                } else if (x != -1 && !visit[x]) {
                    if (x == total) return cnt + 1;
                    q.push({x, cnt + 1});
                    visit[x] = true;
                }
            }
        }
        
        return -1;
    }
};
