class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = (int) intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for (int i = 1; i < n; ++i) {
            auto x = intervals[i];
            if (pq.top() <= x[0]) pq.pop();
            pq.push(x[1]);
        }
        return (int) pq.size();
    }
};