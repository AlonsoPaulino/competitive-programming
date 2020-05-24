class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int>::iterator it;
        int aux = 0, n = nums.size(), ans = 0;
        m[0] = 0;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) ++aux; else --aux;
            if (m.find(aux) != m.end()) {
                ans = max(ans, i + 1 - m[aux]);
            } else {
                m[aux] = i + 1;
            }
        }
        return ans;
    }
};