class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int ans = 0;
        unordered_map<int, int> m;
        for (auto x: nums) {
            m[x]++;
        }
        for (auto x: nums) {
            int y = k - x;
            if ((y != x && m[x] > 0 && m[y] > 0) || (y == x && m[x] > 1)) {
                m[x]--;
                m[y]--;
                ++ans;    
            }
        }
        return ans;
    }
};
