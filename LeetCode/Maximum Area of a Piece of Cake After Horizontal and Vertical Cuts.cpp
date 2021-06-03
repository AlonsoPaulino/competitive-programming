class Solution {
    const long MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int ho = 0, ve = 0;
        int a = 0, b = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (auto x: horizontalCuts) {
            ho = max(ho, x - a);
            a = x;
        }
        ho = max(ho, h - a);
        for (auto x: verticalCuts) {
            ve = max(ve, x - b);
            b = x;
        }
        ve = max(ve, w - b);
        
        long result = (long) ho * (long) ve;
        return (int) (result % MOD);
    }
};
