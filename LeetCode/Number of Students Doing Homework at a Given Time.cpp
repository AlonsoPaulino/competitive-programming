class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = startTime[i];
            int y = endTime[i];
            if (queryTime >= x && queryTime <= y) {
                ++ans;
            }
        }
        return ans;
    }
};