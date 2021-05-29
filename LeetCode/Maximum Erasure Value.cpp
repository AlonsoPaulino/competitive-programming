class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j = 0, sum = 0, ans = 0;
        unordered_set<int> st;
        
        for (int i = 0; i < nums.size(); ++i) {
           int x = nums[i];
            if (st.find(x) == st.end()) {
                st.insert(x); 
                sum += x;
            } else {
                ans = max(ans, sum);
                while (j < nums.size() && nums[j] != x) {
                    st.erase(nums[j]);
                    sum -= nums[j];
                    ++j;
                }
                ++j;
            }
        }
        
        ans = max(ans, sum);
        
        return ans;
    }
};
