class Solution {
public:
    bool check(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) nums.push_back(nums[i]);
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            bool asc = true;
            for (int j = 1; j < n; ++j) {
                if (nums[i + j] < a) {
                    asc = false;
                    break;
                }
                a = nums[i + j];
            }
            if (asc) return true;
        }
        return false;
    }
};

// Another solution written at 02/07/2021
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = (int) nums.size();
        int a = nums[0], x = nums[0];
        
        int i = 1;
        while (i < n && nums[i] >= x) {
            x = nums[i++];
        }
        
        if (i == n) return true; 
        
        x = nums[i++];
        
        while (i < n && nums[i] >= x) {
            x = nums[i++];    
        }
        
        return i == n && nums[i - 1] <= a;
    }
};
