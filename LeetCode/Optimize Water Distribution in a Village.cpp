#define pii pair<int, int>
#define piii pair<int, pii>
#define se second
#define fi first

class Solution {
public:
    vector<int> v;
    
    int find(int x) {
        if (v[x] == x) return x;
        return v[x] = find(v[x]);
    }
    
    void join(int x, int y) {
        v[find(x)] = find(y);
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        v = vector<int>(n + 5, 0);
        vector<piii> edges;
        
        for (int i = 0; i <= n; ++i) v[i] = i;
        for (auto ady: pipes) edges.push_back({ ady[2], { ady[0], ady[1] } });
        for (int i = 0; i < n; ++i) edges.push_back({ wells[i], { 0, i + 1 }});
        
        sort(edges.begin(), edges.end());
        
        int ans = 0;
        
        for (auto e: edges) {
            if (find(e.se.fi) != find(e.se.se)) {
                join(e.se.fi, e.se.se);
                ans += e.fi;
            }
        }
        
        return ans;
    }
};
