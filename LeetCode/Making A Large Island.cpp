class Solution {
public:
    vector<int> cnt;
    vector<int> dsu;
    
    int di[4] = { 0, 0, 1, -1 };
    int dj[4] = { 1, -1, 0, 0 };
    
    void join(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        dsu[rx] = ry;
        cnt[ry] += cnt[rx];        
    }
    
    int find(int x) {
        if (dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        dsu = vector<int>(n * n + 5, 0);
        cnt = vector<int>(n * n + 5, 0);
        for (int i = 0; i < n * n; ++i) {
            dsu[i] = i, cnt[i] = 1;   
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i + 1 < n && grid[i + 1][j] == 1) join(i * n + j, (i + 1) * n + j);
                    if (j + 1 < n && grid[i][j + 1] == 1) join(i * n + j, i * n + j + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    set<int> st;
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + di[k], jj = j + dj[k];
                        if (ii >= 0 && ii < n && jj >= 0 && jj < n && grid[ii][jj] == 1) {
                            int x = find(ii * n + jj);
                            if (st.find(x) == st.end()) {
                                st.insert(x);
                                area += cnt[x];
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        for (auto x: cnt) {
            ans = max(ans, x);
        }
        return ans;
    }
};
