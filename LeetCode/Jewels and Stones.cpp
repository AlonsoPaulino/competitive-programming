class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> m;
        int ans = 0;
        for (auto& x: J) {
            m[x] = true;
        }
        for (auto& x: S) {
           if (m[x]) ++ans;
        }
        return ans;
    }
};