class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = (int) s.size(), x = 0;
        
        for (int i = 0; i < n; ++i) {
            char c = tolower(s[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                i < n / 2 ? ++x : --x;
            }
        }
        
        return x == 0;
    }
};
