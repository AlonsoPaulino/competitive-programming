class Solution {
    map<pair<int, int>, int> m;
public:
    int check(int q, int r) {
        auto x = m.find({q, r});
        if (x == m.end()) {
            return -1;
        }
        return x->second;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        bool neg = false;
        
        long num = (long) numerator, den = (long) denominator;
        
        if (num < 0L && den > 0L) neg = true;
        else if (num > 0L && den < 0L) neg = true;
        
        if (num < 0) num *= -1L;
        if (den < 0) den *= -1L;
        
        long q = num / den;
        long r = num % den;
        
        if (r == 0) {
            ans = to_string(q);
        } else {
            ans = to_string(q);
            ans += ".";
            num = r * 10L;
            
            while (true) {            
                long q = num / den;
                long r = num % den;

                if (r == 0L) {
                    ans += to_string(q);
                    break;
                }

                int ocurr = check(q, r);

                if (ocurr == -1) {
                    m[{q, r}] = ans.size();
                    ans += to_string(q);
                    num = r * 10L;
                } else {
                    string a = ans.substr(0, ocurr);
                    string b = ans.substr(ocurr, ans.size() - ocurr);
                    ans = a + "(" + b + ")";
                    break;
                }   
            }   
        }
        
        if (neg) return "-" + ans;
        return ans;
    }
};
