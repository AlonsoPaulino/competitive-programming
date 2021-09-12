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

// Another solution written on 09/05/2021
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = (int) s.size();
        int sg = 1;
        while (i < n && s[i] == ' ') ++i;
        if (i < n) {
            if (s[i] == '+') sg = 1, ++i;
            else if (s[i] == '-') sg = -1, ++i;
        }
        if (i >= n || s[i] < '0' || s[i] > '9') {
            return 0;
        }
        long long x = 0LL;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            x *= 10LL;
            x += (s[i] - '0');
            if (sg == -1 && x > INT_MAX) {
                x = INT_MAX + 1LL;
                break;
            }
            if (sg == 1 && x >= INT_MAX) {
                x = INT_MAX;
                break;
            }
            ++i;
        }
        if (sg == -1) {
            x = x * sg;
            return (int) x;
        } else {
            return x;
        }
    }
};
