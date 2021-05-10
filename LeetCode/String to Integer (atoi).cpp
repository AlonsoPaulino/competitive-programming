class Solution {
public:
    int myAtoi(string s) {        
        long long ans = 0LL;
        int n = (int) s.size();
        long long sign = 1LL, mul = 10;
        bool valid = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (valid) break;
                continue;
            }
            if (s[i] == '+') {
                if (valid) break;
                valid = true;
                continue;
            }
            if (s[i] == '-') {
                if (valid) break;
                valid = true;
                sign = -1LL;
                continue;
            }
            
            if (s[i] >= '0' && s[i] <= '9') {
                ans *= mul;
                ans += (s[i] - '0');
                valid = true;
                
                if (ans * sign < INT_MIN) {
                    return INT_MIN;
                }
                if (ans * sign > INT_MAX) {
                    return INT_MAX;
                }
                
            } else break;
        }
        return (int) ans * sign;
    }
};
