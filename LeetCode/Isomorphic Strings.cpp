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