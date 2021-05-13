class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        long a = (long) dividend, b = (long) divisor;
        
        if (dividend < 0 && divisor < 0) {
            a = (long) dividend, b = (long) divisor;
            a = -a, b = -b;
        } else if (dividend < 0) {
            sign = -1;
            a = dividend, a = -a;
        } else if (divisor < 0) {
            sign = -1;
            b = divisor, b = -b;
        }
        
        if (a < b) return 0;
        
        long ans = 1L;
        long acum = b;
        
        while (acum < INT_MAX && acum + acum <= a) {
            acum += acum;
            ans += ans;
        }
        
        while (acum < INT_MAX && acum + b <= a) {
            acum += b;
            ans += 1L;
        }
        
        if (sign == -1 && ans - 1 > INT_MAX) return INT_MAX;
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        
        if (sign == -1) return -ans;
        
        return ans;
    }
};
