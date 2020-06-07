class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];
        vector<pair<int, int>> v;
        for (auto x: arr) {
            v.push_back({x, abs(x - m)});
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};