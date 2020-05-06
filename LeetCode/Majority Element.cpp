class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n2 = nums.size() / 2;
        for(auto& x: nums) {
            if (++m[x] > n2) return x;
        }
        return -1;
    }
};