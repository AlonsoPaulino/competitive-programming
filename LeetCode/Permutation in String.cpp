class Solution {
    unordered_map<char, int> m;
public:
    bool exists(char c) {
        return m.find(c) != m.end();
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        for (char c: s1) m[c]++;
        
        int i = 0, n2 = s2.size();
        
        while (i <= n2 - n1) {
            if (!exists(s2[i])) {
                ++i;
                continue;
            }
            
            unordered_map<char, vector<int>> cnt;
            cnt[s2[i]].push_back(i);
            
            bool inclusion = true;
            
            for (int j = 1; j < n1; ++j) {
                int k = i + j;
                if (exists(s2[k])) {
                    cnt[s2[k]].push_back(k);
                    int sk = cnt[s2[k]].size();
                    if (sk > m[s2[k]]) {
                        i = cnt[s2[k]][0] + 1;
                        // cout << s2[k] << endl;
                        // cout << m[s2[k]] << endl;
                        // cout << "#1: " << i << endl;
                        inclusion = false;
                        break;
                    }
                } else {
                    i = k + 1;
                    // cout << "#2: " << i << endl;
                    inclusion = false;
                    break;
                }
            }
            
            if (inclusion) {
                return true;
            }
        }
        
        return false;
    }
};
