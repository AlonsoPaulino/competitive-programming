class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double, vector<int>>> v;
        for (auto p: points) {
            int x = p[0], y = p[1];
            v.push_back({sqrt(x * x + y * y), p});
        }
        sort(v.begin(), v.end(), [](const pair<double, vector<int>> a, const pair<double, vector<int>> b){
            return a.first < b.first;
        });
        vector<vector<int>> ans;
        for (int i = 0; i < K; ++i) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};