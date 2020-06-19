class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int) citations.size();
        int l = 0, r = n - 1, k = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int x = citations[m];
            if (x >= n - m) {
                k = max(k, n - m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return k;
    }
};