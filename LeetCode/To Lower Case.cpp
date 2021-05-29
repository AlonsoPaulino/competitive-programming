class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for (auto x: s) ans += tolower(x);
        return ans;
    }
};
