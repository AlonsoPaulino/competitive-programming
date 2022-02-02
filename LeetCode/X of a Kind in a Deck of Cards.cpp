class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto it: deck) {
            m[it]++;
        }
        int ans = -1;
        for (auto it: m) {
            if (ans == -1) {
                ans = it.second;
            } else {
                ans = gcd(ans, it.second);
            }
        }
        return ans >= 2;
    }
};
