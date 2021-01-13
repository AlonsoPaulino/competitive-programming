class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> m;
        int n = (int) arr.size();
        
        for (int i = 0; i < n; ++i) {
            m[arr[i]] = i;
        }
        
        for (auto p: pieces) {
            int pp = (int) p.size();
            
            if (pp == 1) {
                if (m.find(p[0]) == m.end()) {
                    return false;
                }
                continue;
            }
            
            for (int i = 0; i + 1 < pp; ++i) {
                int a = p[i], b = p[i + 1];
                
                if (m.find(a) == m.end() || m.find(b) == m.end()) {
                    return false;
                }
                
                if (m[b] - m[a] != 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
