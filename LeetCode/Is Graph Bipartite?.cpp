class Solution {
    int n = 0;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = (int) graph.size();
        vector<int> v(n + 5, 0);
        
        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) {
                bool valid = dfs(i, v, graph);
                if (!valid) return false;
            }
        }
        
        return true;
    }
    
    bool dfs(int x, vector<int>& v, vector<vector<int>>& graph) {
        stack<int> st;
        st.push(x);
        v[x] = 1;
        
        while (!st.empty()) {
            int u = st.top(); st.pop();
            auto ady = graph[u];
            for (auto x: ady) {
                if (v[x] == 0) {
                    v[x] = v[u] * -1;
                    st.push(x);
                } else if (v[x] == v[u]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
