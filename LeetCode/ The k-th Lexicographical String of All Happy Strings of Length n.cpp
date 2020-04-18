class Solution {
public:
    vector<string> v;
    
    void getString(string s, int n) {
        if (s.size() == n) {
            v.push_back(s);
        } else {
            if (s.size() == 0) {
                getString("a", n);
                getString("b", n);
                getString("c", n);
            } else {
                if (s[s.size() - 1] == 'a') {
                    getString(s + "b", n);
                    getString(s + "c", n);
                } else if (s[s.size() - 1] == 'b') {
                    getString(s + "a", n);
                    getString(s + "c", n);
                } else {
                    getString(s + "a", n);
                    getString(s + "b", n);
                }
            }
            }
    }
    
    string getHappyString(int n, int k) {
        getString("", n);
        sort(v.begin(), v.end());
        if (k - 1 < v.size()) {
            return v[k - 1];
        } else return "";
    }
};