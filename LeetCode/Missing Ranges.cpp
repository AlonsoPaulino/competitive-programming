class Solution {
public:
    string to_range(int x, int y) {
        if (x == y) return to_string(x);
        return to_string(x) + "->" + to_string(y);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = (int) nums.size();
        
        if (n == 0) {
            ans.push_back(to_range(lower, upper));
            return ans;
        }
        
        int lo = lower, hi = nums[0];
        
        if (nums[0] - lo >= 1) {
            ans.push_back(to_range(lo, nums[0] - 1));
            lo = nums[0];
        }
        
        for (int i = 1; i < n; ++i) {
            hi = nums[i];
            
            if (hi - lo >= 2) {
                ans.push_back(to_range(lo + 1, hi - 1));
            }
            
            lo = nums[i];
        }
        
        if (upper - hi >= 1) {
            ans.push_back(to_range(hi + 1, upper));
        }
        
        return ans;
    }
};


// Another solution written at 01/12/2021
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = (int) nums.size();
        
        if (n == 0) {
            if (upper == lower) {
                ans.push_back(to_string(upper));
            } else {
                ans.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return ans;
        }
        
        int lo = lower, hi;
        
        if (nums[0] - lo == 1) {
            ans.push_back(to_string(lo));
            lo = nums[0];
        } else if (nums[0] - lo > 1) {
            ans.push_back(to_string(lo) + "->" + to_string(nums[0] - 1));
            lo = nums[0];
        }
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            hi = x;
            if (hi - lo > 2) {
                ans.push_back(to_string(lo + 1) + "->" + to_string(hi - 1));
            } else if (hi - lo == 2) {
                ans.push_back(to_string((hi + lo) / 2));
            }
            lo = x;
        }
        if (upper - hi == 1) {
            ans.push_back(to_string(upper));
        } else if (upper - hi > 1) {
            ans.push_back(to_string(hi + 1) + "->" + to_string(upper));
        }
        return ans;
    }
};