class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        int x = n;
        while (!m[x]) {
            int s = sum(x);
            m[x] = s;
            x = s;
            
            if (s == 1) {
                return true;
            }
        }
        return false;
    }
    
    int sum(int n) {
        int s = 0;
        while (n > 0) {
            int x = n % 10;
            s += (x * x);
            n /= 10;
        }
        return s;
    }
};