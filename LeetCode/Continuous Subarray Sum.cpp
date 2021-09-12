class Solution {
public:
    int mod(int a, int b) {
        int res = a % b;
        if (res < 0) a += b;
        return res;
    }
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = (int) nums.size();
        int sum = 0;
        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sum = mod(sum, k);
            
            auto x = m.find(sum);
            if (x != m.end()) {
                if (i - x->second > 1) return true;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};

class Solution {
public:
    int mod(int a, int b) {
        int res = a % b;
        if (res < 0) res += b;
        return res;
    }
  
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = (int) nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += mod(nums[i], k);
            sum = mod(sum, k);
            
            auto it = m.find(sum);
            if (it != m.end()) {
                return it->second + 1 < i;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};
