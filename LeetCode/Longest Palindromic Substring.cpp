class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        int ii = 0, jj = 0; 
        vector<vector<bool>> dp(n + 5, vector<bool>(n + 5, false));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (k == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if (dp[i][j]) {
                    ii = i, jj = j;
                }
            }
        }
        string ans = s.substr(ii, jj - ii + 1);
        return ans;
    }
};

// Another solution written in 01/19/2021
class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int k = 0, l = 1;
        
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i + j < n; ++i) {
                int z = i + j;
                
                if (j == 0) dp[i][z] = true;
                else if (j == 1) {
                    dp[i][z] = s[i] == s[z];
                } else {
                    dp[i][z] = s[i] == s[z] && dp[i + 1][z - 1];
                }
                if (dp[i][z]) {
                    l = j + 1, k = i;
                }
            }
        }
    
        return s.substr(k, l);
    }
};
