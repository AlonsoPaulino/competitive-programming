class Solution {
public:
    int countElements(vector<int>& arr) {
        bitset<1005> b;
        int ans = 0;
        for (auto p : arr) {
            b[p] = 1;
        }
        for (auto p : arr) {
            if (b[p + 1]) {
                ans++;
            }
        }
        return ans;
    }
};