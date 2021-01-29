class Solution {
public:
    string getSmallestString(int n, int k) {
        int i = 0, acum = 0;
        string ans = "";
            
        while (i < n) {
            if (i + 1 == n) {
                ans += ('a' + k - acum - 1);
                break;
            }
            int x = 1;
            while (k - acum - x > 26 * (n - i - 1)) {
                ++x;
            }
            char c = 'a' + x - 1;
            acum += x;
            ans += c;
            ++i;
        }
        
        return ans;
    }
};

// Another solution written at 01/28/2021
class Solution {
public:
    string getSmallestString(int n, int k) {
        int acum = 0;
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            int x = max(1, k - acum - 26 * (n - i - 1));
            char c = 'a' + x - 1;
            acum += x;
            ans += c;
        }
        
        return ans;
    }
};
