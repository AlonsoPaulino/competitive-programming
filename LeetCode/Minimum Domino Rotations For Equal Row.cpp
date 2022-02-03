class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = (int) tops.size();
        int ans = -1;
        for (int i = 1; i <= 6; ++i) {
            for (int r = 1; r <= 2; ++r) {
                int cnt = 0;
                bool valid = true;
                if (r == 1) {
                    for (int k = 0; valid && k < n; ++k) {
                        if (tops[k] == i) continue;
                        if (bottoms[k] == i) cnt++;
                        else valid = false;
                    }   
                } else {
                    for (int k = 0; valid && k < n; ++k) {
                        if (bottoms[k] == i) continue;
                        if (tops[k] == i) cnt++;
                        else valid = false;
                    }
                }
                if (!valid) {
                    break;
                } else {
                    if (ans == -1) ans = cnt; else ans = min(ans, cnt);
                }
            }
        }
        return ans;
    }
};
