class Solution {
public:
   int longestPalindrome(string s) {
       unordered_map<char, int> m;
       for (auto c: s) m[c]++;
       auto it = m.begin();
       int even = 0, odd = 0, cnt = 0;
       while (it != m.end()) {
           int x = it->second;
           if (x > 0) {
               if (x % 2 == 0) even += x;
               else odd += (x - 1), cnt++;
           }
           ++it;
       }
       if (cnt > 0) odd = odd + 1;
       return even + odd;
   }
};