class Solution {
public:
    vector<int> ady;
    vector<int> path;
    vector<bool> vis;
    
    int dfs(int x) {
        if (x == -1) {
            return 0;
        }
        if (vis[x]) {
            return path[x];
        }
        vis[x] = true;
        if (path[x] == -1) {
            path[x] = dfs(ady[x]) + 1;
        }
        return path[x];
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = (int) nums.size();
        ady = vector<int>(n + 5, -1);
        path = vector<int>(n + 5, -1);
        vis = vector<bool>(n + 5, false);
        for (int i = 0; i < n; ++i) {
            ady[nums[i]] = nums[nums[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (path[i] == -1) {
                dfs(i);                
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            ans = max(path[i], ans);
        }
        return ans + 1;
    }
};
