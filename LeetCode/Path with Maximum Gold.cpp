class Solution {
public:
    int di[4] = { 1, -1, 0, 0 };
    int dj[4] = { 0, 0, 1, -1 };
    int n = 0, m = 0;
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, 0, grid));
                }
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, int acum, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return acum;
        }
        
        int aux = grid[i][j];
        grid[i][j] = 0;
        
        int res = 0;
        
        for (int k = 0; k < 4; ++k) {
            int ii = i + di[k], jj = j + dj[k];
            res = max(res, dfs(ii, jj, acum + aux, grid));
        }
        
        grid[i][j] = aux;
        
        return res;
    }
};
