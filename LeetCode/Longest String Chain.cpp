class Solution {
public:
    bool chain(string a, string b) {
        int sa = (int) a.size(), sb = (int) b.size();
        if (sa + 1 != sb) return false;
        
        int i = 0, j = 0;
        while (i < sa) {
            if (j - i > 1) return false;
            if (a[i] == b[j]) {
                ++i, ++j;
            } else ++j;
        }
        
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = (int) words.size();
        vector<vector<string>> v(20);
        unordered_map<string, int> m;
        
        for (auto w: words) {
            v[w.size()].push_back(w);
            m[w] = 1;
        }
        
        int ans = 1;
        for (int i = 1; i <= 15; ++i) {
            for (auto a: v[i]) {
                for (auto b: v[i + 1]) {
                    if (chain(a, b)) {
                        m[b] = max(m[a] + 1, m[b]);   
                    }
                    ans = max(ans, m[b]);
                }
            }
        }
        
        return ans;
    }
};
