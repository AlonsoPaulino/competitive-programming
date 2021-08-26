const int MOD = 1e9 + 7;

typedef long long ll;

class Solution {
public:
    int mul(ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    
    int sum(ll a, ll b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }
    
    int numOfWays(int n) {
        ll two = 6LL, three = 6LL;
        for (int i = 2; i <= n; ++i) {
            int x = mul(three, 2);
            
            three = mul(2, two);
            two = mul(3, two);
            
            two = sum(two, x);
            three = sum(three, x);
        }
        return sum(two, three);
    }
};

// 2 colors -> 5 combinations (3 two colors, 2 three colors)
// 3 colors -> 4 combinations (2 two color, 2 three color)
    
// 1: 6 produces 3 colors, 6 produces 2 colors

// 2: 6 * 4 + 6 * 5 = 54
    
//     12 two color, 12 three colors
//     18 two colors, 12 three colors
    
//     30 two colors, 24 three colors
    
    
// 3: 30 * 5 + 24 * 4 = 150 + 96 = 246
