class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = (int) arr.size(), d = 3, i = 0;
        while (i + d - 1 < n) {
            bool res = true;
            for (int k = i; k < i + d; ++k) {
                if (arr[k] % 2 == 0) {
                    i = k + 1;
                    res = false;
                    break;
                }
            }
            if (res) return true;
        }
        return false;
    }
};
