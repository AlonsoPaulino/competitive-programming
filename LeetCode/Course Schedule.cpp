class Solution {
    unordered_map<int, bool> visit;
    unordered_map<int, vector<int>> ady;
    unordered_map<int, bool> check;
    bool is_cycle = false;
public:
    void dfs(int root) {
        visit[root] = true;
        
        for (auto x: ady[root]) {
            if (!check[x] && visit[x]) {
                is_cycle = true;
                break;
            }
            if (!visit[x]) {
                dfs(x);
            }
        }
        
        check[root] = true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = (int) prerequisites.size();
        if (n == 0) return true;
        
        for (auto x: prerequisites) {
            ady[x[1]].push_back(x[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!visit[i]) {
                dfs(i);
                if (is_cycle) return false;
            }
        }
        
        return !is_cycle;
    }
};
