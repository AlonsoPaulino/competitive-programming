class Solution {
public:
    int charToInt(char x) {
        if (x == 'I') return 1;
        else if (x == 'V') return 5;
        else if (x == 'X') return 10;
        else if (x == 'L') return 50;
        else if (x == 'C') return 100;
        else if (x == 'D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
        int n = (int) s.size();
        if (n == 0) return 0;
        
        int ans = 0, a = -1;
        for (int i = 0; i < n; ++i) {
            if (a == -1) {
                a = charToInt(s[i]);
                continue;
            }
            int b = charToInt(s[i]);
            if (b > a) {
                ans += (b - a);
                a = -1;
            } else {
                ans += a;
                a = b;
            }
        }
        ans += max(a, 0);
        
        return ans;
    }
};
