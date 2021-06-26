class Solution {
    vector<int> v;
public:
    void join(int x, int y) {
        v[find(x)] = find(y);
    }
    
    int find(int x) {
        return v[x] == x ? x : v[x] = find(v[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        v = vector<int>(n + 1);
        for (int i = 0; i <= n; ++i) v[i] = i;
        for (auto x: edges) {
            if (find(x[0]) == find(x[1])) return x;
            join(x[0], x[1]);
        }
        return vector<int>();
    }
};
