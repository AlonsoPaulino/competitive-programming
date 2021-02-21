class Solution {
    int ans = 0;
public:
    void solve(int x, int y) {
        if (x == y) return;
        
        if (x < y) {
            ans += y & 1 ? 2 : 1;
            solve(x, (y + 1) / 2);
        } else {
            int diff = x - y;
            ans += diff;
            solve(x - diff, y);
        }
    }
    
    int brokenCalc(int X, int Y) {
        solve(X, Y);
        return ans;
    }
};
