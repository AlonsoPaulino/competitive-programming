class Solution {
public:
    bool isVowel(char c) {
        bool a = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        bool b = c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        return a || b;
    }
    
    string toGoatLatin(string S) {
        string ans = "", a = "a", c = "";
        int n = (int) S.size();
        for (int i = 0; i <= n; ++i) {
            if (S[i] == ' ' || i == n) {
                if (c != "" && c != "#") ans += c;
                ans += "ma";
                ans += a;
                c = "";
                a += "a";
                if (i < n) ans += " ";
                continue;
            }
            if (c == "") {
                if (isVowel(S[i])) {
                    c = "#";
                    ans += S[i];
                } else c = S[i];
            } else {
                ans += S[i];
            }
        }
        return ans;
    }
};