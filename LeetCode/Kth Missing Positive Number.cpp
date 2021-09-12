class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = 0, n = (int) arr.size();
        for (int i = 0; i < n; ++i) {
            int diff = arr[i] - x - 1;
            if (diff >= k) {
                return x + k;
            } else {
                k -= diff;
            }
            x = arr[i];
        }
        return arr[n - 1] + k;
    }
};
