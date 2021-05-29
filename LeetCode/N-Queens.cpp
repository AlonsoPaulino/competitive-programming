typedef vector<string> vs;
typedef vector<bool> vb;

class Solution {
    int n;
    vector<vs> ans;
public:
    void solve(vs v, vb r, vb c, vb d, vb dd, int q) {
        if (q == n) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (r[i] && c[q] && d[i + q] && dd[n - 1 + i - q]) {
                v[i][q] = 'Q';
                r[i] = c[q] = 0;
                d[i + q] = dd[n - 1 + i - q] = 0;
                solve(v, r, c, d, dd, q + 1);
                v[i][q] = '.';
                r[i] = c[q] = 1;
                d[i + q] = dd[n - 1 + i - q] = 1;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int total) {
        n = total;
        vs v(n, string(n, '.'));
        solve(v, vb(n, 1), vb(n, 1), vb(2 * n, 1), vb(2 * n, 1), 0);
        return ans;
    }
};
