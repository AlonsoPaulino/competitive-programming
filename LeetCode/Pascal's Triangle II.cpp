class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        int n = rowIndex;
        long c = (long) 1L;
        for (int k = 1; k <= n / 2; ++k) {
            c = c * (n - k + 1) / k;
            ans[k] = ans[n - k] = (int) c;
        }
        return ans;
    }
};