class Solution {
public:
    unordered_map<int, int> memo;
    
    int f(int x) {
        auto it = memo.find(x);
        if (it != memo.end()) {
            return it->second;
        }
        if (x < 0) return 0;
        if (x == 0) return 1;
        int res = f(x - 1) + f(x - 2);
        memo[x] = res;
        return res;
    }
    
    int numDecodings(string s) {
        int ans = 1, n = (int) s.size();
        int group = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            if (x == 0 && (i == 0 || (s[i - 1] - '0') > 2)) {
                return 0;
            }
            if (x == 0) {
                ans *= f(group - 1);
                group = 0;
            } else if (x > 6 && i > 0 && (s[i - 1] - '0') > 1) {
                ans *= f(group);
                group = 1;
            } else if (i > 0 && (s[i - 1] - '0') > 2) {
                ans *= f(group);
                group = 1;
            } else {
                ++group;
            }
        }
        if (group > 0) {
            ans *= f(group);
        }
        return ans;
    }
};

// Another solution written on 09/10/2021
class Solution {
public:
    unordered_map<int, int> dp;
    
    int numDecodings(string s) {
        int n = (int) s.size();
        return f(s, 0, n);
    }
    
    int f(string &s, int i, int n) {
        if (i == n) {
            return 1;
        }
        
        auto it = dp.find(i);
        if (it != dp.end()) {
            return it->second;
        }
     
        int res = 0;
        if (s[i] != '0') {
            res += f(s, i + 1, n);
            if (i + 1 < n && (s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6'))) {
                res += f(s, i + 2, n);
            }
        }
        return dp[i] = res;
    }
};
