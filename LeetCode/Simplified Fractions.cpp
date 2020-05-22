class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int den = 1; den <= n; ++den) {
            for (int num = 1; num < den; ++num) {
                if (gcd(num, den) == 1) {
                    string tmp = to_string(num);
                    tmp += "/";
                    tmp += to_string(den);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};