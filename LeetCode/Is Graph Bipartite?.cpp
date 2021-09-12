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

// Another solution written on 08/03/2021
class Solution {
public:
    int n = 0;
    vector<int> color;
    
    bool dfs(vector<vector<int>>& g, int x) {
        stack<int> st;
        color[x] = 1;
        st.push(x);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (auto v: g[u]) {
                if (color[v] == 0) {
                    st.push(v);
                    color[v] = color[u] * -1;
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        n = (int) graph.size();
        color = vector<int>(n + 5, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                int res = dfs(graph, i);
                if (!res) return false;
            }
        }
        return true;
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = (int) graph.size();
        vector<int> color(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                stack<int> st;
                color[i] = 1;
                st.push(i);
                while (!st.empty()) {
                    int u = st.top(); st.pop();
                    int c = color[u];
                    for (auto v: graph[u]) {
                        if (color[v] == 0) {
                            color[v] = c * -1;
                            st.push(v);
                        } else {
                            if (color[v] == c) return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
