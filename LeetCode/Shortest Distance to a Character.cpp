class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        vector<int> vc;
        int n = (int) s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) vc.push_back(i);
        }
        
        int k = -1, ks = (int) vc.size();
        int a = -1, b = -1;
        
        if (ks > 0) b = vc[++k];
        
        for (int i = 0; i < n; ++i) {
            if (b != -1 && i > b) {
                a = b;
                b = (k + 1 >= ks) ? -1 : vc[++k];
            }
            if (a == -1 && b >= 0) {
                ans.push_back(abs(b - i));
            } else if (b == -1 && a >= 0) {
                ans.push_back(abs(a - i));
            } else if (a >= 0 && b >= 0) {
                ans.push_back(min(abs(b - i), abs(a - i)));
            }
        }
        
        return ans;
    }
};
