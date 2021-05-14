class Solution {
    vector<string> ans;
public:
    bool is_valid_comma(string x) {
        int n = (int) x.size();
        if (n > 1 && x[0] == '0') return false;
        return true;
    }
    
    bool is_valid_point(string a, string b) {
        int na = (int) a.size(), nb = (int) b.size();
        if (na > 1 && a[0] == '0') return false;
        if (b[nb - 1] == '0') return false;
        return true;
    }
    
    vector<string> get_valid_set_with_points(string x) {
        vector<string> res;
        int n = (int) x.size();
        
        for (int i = 1; i < n; ++i) {
            string in = x.substr(0, i);
            string dec = x.substr(i, n - i);
            
            if (is_valid_point(in, dec)) {
                res.push_back(in + "." + dec);
            }
        }
        
        return res;
    }
    
    void check_point(string a, string b) {
        bool a_valid = is_valid_comma(a), b_valid = is_valid_comma(b);
        auto pa = get_valid_set_with_points(a), pb = get_valid_set_with_points(b);
        
        if (a_valid && b_valid) ans.push_back("(" + a + ", " + b + ")");
        if (b_valid) for (auto xa: pa) ans.push_back("(" + xa + ", " + b + ")");
        if (a_valid) for (auto xb: pb) ans.push_back("(" + a + ", " + xb + ")");
        for (auto xa: pa) for (auto xb: pb) ans.push_back("(" + xa + ", " + xb + ")");
    }
    
    void check_comma(string x) {
        int n = (int) x.size();
        string a, b;
        for (int i = 2; i < n - 1; ++i) {
            a = x.substr(1, i - 1);
            b = x.substr(i, n - i - 1);
            check_point(a, b);
        }
    }
    
    vector<string> ambiguousCoordinates(string s) {
        check_comma(s);
        return ans;
    }
};
