class Solution {
    unordered_map<int, string> m;
public:
    string say(string s) {
        string result;
        int i = 0, n = (int) s.size();
        while (i < n) {
            int a = i, cnt = 1;
            while (i + 1 < n && s[i + 1] == s[a]) {
                ++i, ++cnt;
            }
            result += to_string(cnt);
            result += s[a];
            ++i;
        }
        
        return result;
    }
    
    string countAndSay(int n) {
        m[1] = "1";
        
        for (int i = 2; i <= n; ++i) {
            m[i] = say(m[i - 1]);
        }
        
        return m[n];
    }
};
