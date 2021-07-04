class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b) {
            return a[0] < b[0]; 
        });
        vector<vector<int>> ans;
        
        int lo = -1, hi = -1;
        for (auto x: intervals) {
            if (lo == -1 && hi == -1) {
                lo = x[0], hi = x[1];
                continue;
            }
            if (x[0] <= hi) {
                hi = max(hi, x[1]);
            } else {
                ans.push_back({ lo, hi });
                lo = x[0], hi = x[1];
            }
        }
        
        if (lo != -1) ans.push_back({ lo, hi });
        
        return ans;
    }
};
