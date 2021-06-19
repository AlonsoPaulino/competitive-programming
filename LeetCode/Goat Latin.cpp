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

// Another solution written at 06/19/2021
class Solution {
    const string ma = "ma";
    char v[5] = { 'a', 'e', 'i', 'o', 'u' };
public:
    string process_word(string s, int i) {
        string res = "";
        
        char f = tolower(s[0]);
        bool isV = false;
        for (int k = 0; !isV && k < 5; ++k) {
            if (f == v[k]) isV = true;
        }
        
        if (isV) {
            res = s + ma;
        } else {
            res = s.substr(1, s.size() - 1);
            res += s[0];
            res += ma;
        }
        
        for (int k = 0; k < i; ++k) {
            res += "a";
        }
        return res;
    }
    
    string toGoatLatin(string sentence) {
        int n = sentence.size(), iw = 0;
        string ans = "";
        string s = "";
        for (int i = 0; i < n; ++i) {
            if (sentence[i] != ' ') {
                s += sentence[i];
            } else {
                if (ans.size() > 0) ans += " ";
                ans += process_word(s, ++iw);
                s = "";
            }
        }
        if (s.size() > 0) {
            if (ans.size() > 0) ans += " ";
            ans += process_word(s, ++iw);
        }
        return ans;
    }
};
