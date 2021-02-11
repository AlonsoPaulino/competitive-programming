class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = (int) s.size(), nt = (int) t.size();
        if (ns != nt) return false;
        
        unordered_map<char, int> m;
        
        for (auto x: s) m[x]++;
        for (auto x: t) {
            if (m.find(x) == m.end()) return false;
            if (--m[x] < 0) return false;
        }
        
        return true;
    }
};
