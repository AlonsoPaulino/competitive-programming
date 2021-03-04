class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        
        for (auto x: nums) m[x]++;
        
        for (auto x: m) {
            int num = x.first, count = x.second;
            if (m.find(num + 1) != m.end()) {
                ans = max(ans, count + m[num + 1]);
            }
            if (m.find(num - 1) != m.end()) {
                ans = max(ans, count + m[num - 1]);
            }
        }
            
        return ans;
    }
};
