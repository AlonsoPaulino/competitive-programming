class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, h = 0, n = (int) gain.size();
        for (int i = 0; i < n; ++i) {
            h += gain[i];
            ans = max(ans, h);
        }
        return ans;
    }
};
