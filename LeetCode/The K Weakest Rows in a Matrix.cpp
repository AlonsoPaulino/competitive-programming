class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = (int) mat.size(), m = n > 0 ? (int) mat[0].size() : 0;
        vector<pair<int, int>> x(n);
        
        for (int i = 0; i < n; ++i) {
            x[i].first = i;
            for (int j = 0; j < m; ++j) {
                x[i].second += mat[i][j];
            }
        }
        
        sort(x.begin(), x.end(), [](pair<int, int>& a, pair<int, int>& b){
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(x[i].first);
        }
        
        return ans;
    }
};
