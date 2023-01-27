class Solution {
public:
    const int INF = 100000009;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> g(n + 5, vector<int>(n + 5, INF));
        for (auto x: flights) {
            g[x[0]][x[1]] = x[2];
        }
        
        int dp[n + 5][n + 5][n + 5];
        
        for (int k = 0; k <= K + 1; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j][k] = INF;
                    
                    if (k == 0) {
                        if (i == j) dp[i][j][k] = 0;
                    } else if (k == 1) {
                        if (g[i][j] != INF) dp[i][j][k] = g[i][j];
                    } else {
                        for (int x = 0; x < n; ++x) {
                            if (g[i][x] != INF && i != x && j!= x && dp[x][j][k - 1] != INF) {
                                dp[i][j][k] = min(dp[i][j][k], g[i][x] + dp[x][j][k - 1]);    
                            }
                        }
                    }
                }
            }            
        }
        
        int ans = INF;
        for (int x = 0; x <= K + 1; ++x) {
            ans = min(ans, dp[src][dst][x]);
        }
        
        return ans != INF ? ans : -1;
    }
};

// New solution written on Jan 27, 2023
class Solution {
public:
    const int INF = 1e9;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> g(n + 5, vector<vector<int>>(n + 5, vector<int>(k + 5, INF)));
        for (auto &f: flights) {
            g[f[0]][f[1]][0] = f[2];
        }

        int result = g[src][dst][0];

        for (int t = 1; t <= k; ++t) {
            for (int j = 0; j < n; ++j) {
                int dist = INF;
                for (int x = 0; x < n; ++x) {
                    if (x != j && x != src) {
                        dist = min(dist, g[src][x][t - 1] + g[x][j][0]);
                    }
                }

                g[src][j][t] = dist;
                if (j == dst) {
                    result = min(result, g[src][j][t]);
                }
            }
        }

        if (result >= INF) {
            return -1;
        }
        return result;
    }
};
