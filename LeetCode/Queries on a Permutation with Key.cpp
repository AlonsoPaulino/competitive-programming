class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m + 5);
        vector<int> ans;
        for (int i = 1; i <= m; ++i) v[i] = i - 1;
        for (auto &q : queries) {
            ans.push_back(v[q]);
            for (int i = 1; i <= m; ++i) {
                if (v[i] < v[q]) {
                    v[i]++;
                }
            }
            v[q] = 0;
        }
        return ans;
    }
};