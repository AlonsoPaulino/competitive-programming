#define pii pair<int, int>
#define fi first
#define se second

struct Node {
    int x;
    int d;
    Node(int x, int d) : x(x), d(d) {}
};

bool operator < (const Node &a, const Node &b) { 
    return a.d > b.d; 
}

const int INF = 10e9 + 7;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

class Solution {
public:    
    vector<int> get_ady(int x, int n, int m) {
        vector<int> res;
        int i = x / m, j = x % m;
        for (int k = 0; k < 4; ++k) {
            int ii = i + dx[k], jj = j + dy[k];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) res.push_back(ii  * m + jj);
        }
        return res;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<bool> visited(n * m + 5, false);
        vector<int> dist(n * m + 5, INF);
        
        priority_queue<Node> pq;
        pq.push(Node(0, grid[0][0]));
        
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            int u = node.x;
            int d = node.d;
            
            if (visited[u]) continue;
            
            auto ady = get_ady(u, n, m);
            
            for (auto x: ady) {
                int i = x / m, j = x % m;
                int cost = max(grid[i][j], d);
                
                if (!visited[x] && cost <= dist[x]) {
                    dist[x] = cost;
                    pq.push(Node(x, cost));
                }
            }
            
            visited[u] = true;
        }
        
        return dist[n * m - 1];
    }
};
