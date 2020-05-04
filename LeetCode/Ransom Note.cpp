class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (auto& c: magazine) m[c]++;
        bool ans = true;
        for (auto& c: ransomNote) {
            if (m[c] > 0) m[c]--;
            else {
                ans = false;
                break;
            }
        }
        return ans;
    }
};