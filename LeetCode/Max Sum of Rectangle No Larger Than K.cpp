class Solution {
public:
    int solve(vector<int> v, int k) {
        int n = (int) v.size();
        int res = INT_MIN;
        set<int> st; st.insert(0);
        for (int i = 1; i < n; ++i) {
            v[i] += v[i - 1];
        }
        for (int j = 0; j < n; ++j) {
            auto it = lower_bound(st.begin(), st.end(), v[j] - k);
            if (it != st.end()) {
                res = max(v[j] - *it, res);
            }
            if (res == k) return res;
            st.insert(v[j]);
        }
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = (int) matrix.size();
        int m = (int) matrix[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) { 
            for (int j = 1; j < m; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int l = 0; l < m; ++l) {
            for (int r = l; r < m; ++r) {
                vector<int> v;
                for (int i = 0; i < n; ++i) {
                    int sum = matrix[i][r] - (l > 0 ? matrix[i][l - 1] : 0);
                    v.push_back(sum);
                }
                int res = solve(v, k);
                ans = max(ans, res);
                if (ans == k) return ans;
            }
        }
        return ans;
    }
};
