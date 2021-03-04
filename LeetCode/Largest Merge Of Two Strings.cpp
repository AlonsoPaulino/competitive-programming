class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        
        while (true) {
            int a = (int) word1.size(), b = (int) word2.size();
            if (a == 0 && b == 0) break;
            if (a == 0) {
                ans += word2[0];
                word2 = word2.substr(1, b - 1);
            } else if (b == 0) {
                ans += word1[0];
                word1 = word1.substr(1, a - 1);
            } else {
                if (word1 < word2) {
                    ans += word2[0];
                    word2 = word2.substr(1, b - 1);
                } else {
                    ans += word1[0];
                    word1 = word1.substr(1, a - 1);
                }
            }
        }
        
        return ans;
    }
};
