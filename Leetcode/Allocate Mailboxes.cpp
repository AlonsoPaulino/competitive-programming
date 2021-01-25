class Solution {
    vector<vector<int>> dist;
    vector<vector<int>> mem;
    
    const int INF = 1e7;
public:
    int minDistance(vector<int>& houses, int k) {
        int n = (int) houses.size();
        sort(houses.begin(), houses.end());
    
        dist = vector<vector<int>>(n, vector<int>(n, 0));
        mem = vector<vector<int>>(k + 5, vector<int>(n + 5, -1));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; i + k < j - k; ++k) {
                    dist[i][j] += (houses[j - k] - houses[i + k]);
                }
            }
        }
        
        int ans = dp(houses, n, k, 0);
        return ans;
    }
    
    int dp(vector<int> houses, int n, int k, int i) {
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INF;
        if (mem[k][i] != -1) return mem[k][i];
        
        int result = INF;
        
        for (int j = i; j < n; ++j) {
            result = min(result, dist[i][j] + dp(houses, n, k - 1, j + 1));
        }
        
        return mem[k][i] = result;
    }
};
