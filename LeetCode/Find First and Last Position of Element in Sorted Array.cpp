class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1, b = -1;
        int n = (int) nums.size();
        int lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int x = nums[mid];
            
            if (x == target) {
                if (a == -1 && (mid == 0 || nums[mid - 1] != target)) {
                    a = mid;
                    lo = mid, hi = n - 1;
                } else if (b == -1 && (mid == n - 1 || nums[mid + 1] != target)) {
                    b = mid;
                    hi = mid - 1, lo = 0;
                } else {
                    if (a == -1) hi = mid;
                    else lo = mid + 1;
                }
            } else if (x < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};
