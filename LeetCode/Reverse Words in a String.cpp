class Solution {
public:
    vector<string> split(string s) {
        int n = (int) s.size();
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (tmp.size() > 0) {
                    res.push_back(tmp);   
                }
                tmp = "";
            } else {
                if (s[i] != ' ') tmp += s[i];   
            }
        }
        if (tmp.size() > 0) {
            res.push_back(tmp);
        }
        return res;
    }
    
    string reverseWords(string s) {
        string ans = "";
        vector<string> x = split(s);
        int n = (int) x.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans += " ";
            }
            ans += x[n - i - 1];
        }
        return ans;
    }
};
