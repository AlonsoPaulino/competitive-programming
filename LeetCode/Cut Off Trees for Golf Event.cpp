struct Node {
    int i, j;
    int val = 0;
    Node(int i, int j, int val): i(i), j(j), val(val) {}
};

bool operator < (const Node& a, const Node& b) {
    return a.val < b.val;
}

class Solution {
    vector<vector<int>> f;
    vector<Node> v;
    int n = 0, m = 0;
public:
    
    int di[4] = { -1, 1, 0, 0 };
    int dj[4] = { 0, 0, 1, -1 };
    
    bool is_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int bfs(int i, int j, int ti, int tj) {   
        if (i == ti && j == tj) return 0;
        
        queue<Node> q;
        q.push(Node(i, j, 0));
        
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int ii = u.i + di[i], jj = u.j + dj[i];
                if (is_valid(ii, jj) && !visit[ii][jj]) {     
                    if (ii == ti && jj == tj) {
                        f[ii][jj] = 1;
                        return u.val + 1;
                    } else if (f[ii][jj] > 0) {
                        q.push(Node(ii, jj, u.val + 1));
                        visit[ii][jj] = true;
                    }
                }
            }
        }
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        f = forest, n = (int) forest.size();
        if (n == 0) return 0; else m = (int) forest[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j] > 1) v.push_back(Node(i, j, f[i][j]));
            }
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0, i = 0, j = 0;
        
        for (auto x: v) {
            int res = bfs(i, j, x.i, x.j);
            if (res == -1) {
                return -1;
            }
            i = x.i, j = x.j;
            ans += res;
        }
        
        return ans;
    }
};
