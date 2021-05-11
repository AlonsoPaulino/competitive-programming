class Solution {
    const int N = 5000005;
    vector<bool> v = vector<bool>(N, true);
public:
    
    void sieve() {
        v[0] = v[1] = 0;
        for (long i = 2; i * i < N; ++i) {
            if (v[i]) {
                for (long j = i * i; j < N; j += i) {
                    v[j] = 0;
                }   
            }
        }
    }
    
    int countPrimes(int n) {
        sieve();
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (v[i]) ++ans;
        }
        return ans;
    }
};
