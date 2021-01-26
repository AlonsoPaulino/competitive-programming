struct Node {
    int i, j, val;
    int d = 0;
    Node(int i, int j, int val): i(i), j(j), val(val) {}
};

bool operator < (const Node&a, const Node &b) { 
    return a.d > b.d; 
};

class Solution {
    const int INF = 1e9;
    
    int di[4] = { -1, 1, 0, 0 };
    int dj[4] = { 0, 0, 1, -1 };
    int n, m;
public:
    bool is_valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = (int) heights.size();
        if (n == 0) return 0;
        
        m = (int) heights[0].size();
        
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, INF));
        priority_queue<Node> pq;
        
        int ri = n - 1, rj = m - 1;
        
        Node src = Node(ri, rj, heights[ri][rj]);
        
        dist[ri][rj] = 0;
        pq.push(src);
        
        while (!pq.empty()) {
            Node u = pq.top(); pq.pop();
            
            if (visit[u.i][u.j]) continue;
            
            for (int k = 0; k < 4; ++k) {
                int ki = di[k], kj = dj[k];
                int ii = u.i + ki, jj = u.j + kj;
                
                if (is_valid(ii, jj) && !visit[ii][jj]) {
                    Node v = Node(ii, jj, heights[ii][jj]);
                    int x = max(dist[u.i][u.j], abs(v.val - u.val));
                    
                    if (x < dist[v.i][v.j]) {
                        dist[v.i][v.j] = x;
                        v.d = x;
                        pq.push(v);
                    }
                }
            }
            
            visit[u.i][u.j] = true;
        }
        
        return dist[0][0];
    }
};
