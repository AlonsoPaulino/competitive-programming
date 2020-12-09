class Solution {
    const int N = 60;
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(N, 0);
        for (auto x: time) v[x % 60]++;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (i == j) {
                    if (v[i] > 1 && (i * 2) % 60 == 0) {
                        ans += v[i] * (v[i] - 1) / 2;
                    }
                } else if (v[i] > 0 && v[j] > 0 && (i + j) % 60 == 0) {
                    ans += v[i] * v[j];
                }
            }
        }
        return ans;
    }
};