class Solution {
public:
    bool sub_string(string p, string t) {
        int n = (int) p.size();
        for (int i = 0; i < n; ++i) {
            if (p[i] != t[i]) return false;
        }
        return true;
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans = "";
        int n = (int) words.size();
        
        for (int i = 0; i < n; ++i) {
            string s = words[i];
            int asz = (int) ans.size();
            int ssz = (int) s.size();
            if (asz >= ssz) continue;
            int target = ssz - 1, start = i - 1;
            bool found = true;
            while (target > 0) {
                bool found = false;
                for (int j = start; j >= 0; --j) {
                    string x = words[j];
                    int xsz = (int) x.size();
                    if (xsz == target && sub_string(x, s)) {
                        target = target - 1;
                        start = j - 1;
                        found = true;
                        break;
                    }
                }
                if (!found) break;
            }
            if (target == 0) {
                ans = s;
            }
        }
        
        return ans;
    }
};
