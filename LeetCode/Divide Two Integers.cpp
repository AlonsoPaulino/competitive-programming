class Solution {
public:
    int divide(int dividend, int divisor) {
        long sign = 1L;
        long a = (long) dividend, b = (long) divisor;
        
        if (dividend < 0 && divisor < 0) {
            a = dividend * -1L, b = divisor * -1L;
        } else if (dividend < 0) {
            sign = -1L;
            a = dividend * -1L;
        } else if (divisor < 0) {
            sign = -1L;
            b = divisor * -1L;
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
        
        if (sign == -1L && ans - 1 > INT_MAX) return INT_MAX;
        if (sign == 1L && ans > INT_MAX) return INT_MAX;
        
        return (int) ans * sign;
    }
};
