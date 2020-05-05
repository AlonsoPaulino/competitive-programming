class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(30, 0);
        for (auto& x: s) ++v[x - 'a'];
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (v[s[i] - 'a'] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};