class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool ans = true;
        
        int n = (int) s1.size(); // Both same size
        int seq = -1;
        for (int i = 0; i < n && ans; ++i) {
            int x = s1[i], y = s2[i];
            if (x != y) {
                if (seq == -1) {
                    if (x > y) seq = 1; else seq = 0;
                } else {
                    if (seq == 1 && x < y) ans = false;
                    if (seq == 0 && x > y) ans = false;
                }
            }
        }
        
        return ans;
    }
};