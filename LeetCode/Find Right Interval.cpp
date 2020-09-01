class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = (int) intervals.size();
        vector<int> ans(n);
        map<pair<int, int>, int> mm;
        for (int i = 0; i < n; ++i) {
            mm[{intervals[i][0], intervals[i][1]}] = i;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < n; ++i) {
            auto x = intervals[i];
            int idx = -1;
            for (int j = i + 1; j < n; ++j) {
                if (intervals[j][0] >= x[1]) {
                    idx = mm[{intervals[j][0], intervals[j][1]}];
                    break;
                }
            }
            ans[mm[{x[0], x[1]}]] = idx;
        }
        return ans;
    }
};