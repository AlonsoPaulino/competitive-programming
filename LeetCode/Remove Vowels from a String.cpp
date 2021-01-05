class Solution {
public:
    string removeVowels(string s) {
        string ans = "";
        for (auto x: s) {
            if (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') {
                ans += x;
            }
        }
        return ans;
    }
};