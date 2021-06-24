unordered_map<char, int> m;

bool comp(string a, string b) {
    int la = a.size(), lb = b.size();
    int sz = min(la, lb);

    for (int i = 0; i < sz; ++i) {
        if (a[i] == b[i]) continue;
        return m[a[i]] < m[b[i]];
    }

    return a.size() < b.size();
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        m.clear();
        for (int i = 1; i < order.size(); ++i) {
            m[order[i]] = i;
        }
        vector<string> cpy = words;
        sort(cpy.begin(), cpy.end(), comp);
        
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            if (words[i] != cpy[i]) return false;
        }
        
        return true;
    }
};
