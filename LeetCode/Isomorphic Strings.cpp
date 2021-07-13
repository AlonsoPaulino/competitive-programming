class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> iso;
        unordered_map<char, bool> used;
        int n = (int) s.size(), m = (int) t.size();
        if (n != m) return false;
        for (int i = 0; i < n; ++i) {
            char cs = s[i], ct = t[i];
            if (!used[ct] && !iso[cs]) {
                iso[cs] = ct;
                used[ct] = true;
            } else if(iso[cs] != ct) return false; 
        }
        return true;
    }
};

// Another solution written on 07/12/2021
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sm, tm;
        int n = (int) s.size(); // s.lenght == t.length
        
        for (int i = 0; i < n; ++i) {
            char cs = s[i], ct = t[i];
            auto its = sm.find(cs), itt = tm.find(ct);
            if (its == sm.end() && itt != tm.end()) return false;
            if (its != sm.end() && itt == tm.end()) return false;
            if (its == sm.end() && itt == tm.end()) {
                sm[cs] = ct, tm[ct] = cs;
                continue;
            }
            if (its->second != ct || itt->second != cs) {
                return false;
            }
        }
        
        return true;
    }
};
