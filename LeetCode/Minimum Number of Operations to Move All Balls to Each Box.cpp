class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int) boxes.size();
        vector<int> sum(n), cnt(n), ans(n);
        sum[0] = 0;
        cnt[0] = boxes[0] - '0';
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + (boxes[i] == '1' ? i : 0);
            cnt[i] = cnt[i - 1] + (boxes[i] == '1' ? 1 : 0);
        }
        for (int i = 0; i < n; ++i) {
            int right = sum[n - 1] - sum[i];
            int left = i > 0 ? sum[i - 1] : 0;
            int fr = cnt[n - 1] - cnt[i];
            int fl = i > 0 ? cnt[i - 1] : 0;
            ans[i] = right - i * fr + i * fl - left;
        }
        return ans;
    }
};
