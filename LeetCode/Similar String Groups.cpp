class Solution {
public:
    vector<int> dsu;
    
    int find(int x) {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }
    
    void join(int x, int y) {
        dsu[find(x)] = find(y);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = (int) strs.size();
        unordered_map<string, int> m;
        dsu = vector<int>(n + 5, 0);
        for (int i = 0; i < n; ++i) {
            m[strs[i]] = i;
            dsu[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            string s = strs[i];
            int sz = (int) s.size();
            for (int j = 0; j < sz; ++j) {
                for (int k = j + 1; k < sz; ++k) {
                    swap(s[j], s[k]);
                    auto it = m.find(s);
                    if (it != m.end()) {
                        join(i, it->second);
                    }
                    swap(s[k], s[j]);
                }
            }
        }
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(find(m[strs[i]]));
        }
        return st.size();
    }
};
