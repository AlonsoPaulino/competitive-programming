class Solution {
public: 
    vector<string> split_two(string s, char x) {
        string a, b;
        vector<string> res;
        int n = (int) s.size();
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!found && tolower(s[i]) == x) {
                found = true;
                continue;
            }
            found ? b += s[i] : a += s[i];
        }
        if (found) {
            res.push_back(a);
            res.push_back(b);
        }
        return res;
    }
    
    bool check_int(string s, bool accept_e, bool accept_sign, bool accept_zero) {
        int n = (int) s.size();
        if (accept_e) {
            auto v = split_two(s, 'e');
            if (v.size() == 2) {
                return check_int(v[0], false, accept_sign, accept_zero)
                    && check_int(v[1], false, true, false);
            }
        }
        int i = 0, digits = 0;
        if (s[i] == '-' || s[i] == '+') {
            if (accept_sign) ++i;
            else return false;
        }
        
        for (i; i < n; ++i, ++digits) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        
        return accept_zero ? true : digits > 0;
    }
    
    bool isNumber(string s) {
        int n = (int) s.size();
        if (n < 1) return false;
        int i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == n) return false;
        auto v = split_two(s, '.');
        if (v.size() == 2) {
            int a = (int) v[0].size(), b = (int) v[1].size();
            if (a == 0 && b == 0) return false;
            if (a == 0 && b != 0) {
                return check_int(v[1], true, false, false);   
            }
            if (a != 0 && b == 0) {
                return check_int(v[0], false, true, false);
            }
            return check_int(v[0], false, true, true) && check_int(v[1], true, false, true);
        }
        return check_int(s, true, true, false);
    }
};
