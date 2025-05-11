class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = (int) values.size(), result = 0;
        vector<pair<int, int>> v(n, { 0, 0 });
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            v[i] = { values[i], labels[i] };
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        for (int i = 0, cnt = 0; i < n && cnt < numWanted; ++i) {
            pair<int, int> p = v[i];
            if (m[p.second] + 1 <= useLimit) {
                result += p.first;
                m[p.second]++, cnt++;                
            }
        }
        return result;
    }
};
