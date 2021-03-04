class Solution {
    const int MOD = 1e9 + 7;
    unordered_map<int, int> mem;
public:
    int sum(int a, int b) {
        return (a % MOD + b % MOD) % MOD;
    }
    
    int mul(int a, int b) {
        return (a % MOD * b % MOD) % MOD;
    }
    
    int concatenatedBinary(int n) {
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            int d = log2(i) + 1;
            
            for (auto x = 0; x < d; ++x) {
                ans = mul(ans, 2);
            }
            
            ans = sum(ans, i);
        }
        return ans;
    }
};
