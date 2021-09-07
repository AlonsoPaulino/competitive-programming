class Solution {
public:
    vector<int> v;
    int n, sum = 0;
    map<pair<int,int>, bool> memo;
    
    bool f(int target, int i) {
        auto it = memo.find({target, i});
        if (it != memo.end()) {
            return it->second;
        }
        if (target < 0 || i >= n) return false;
        if (v[i] == target) {
            return true;
        }
        bool res = f(target - v[i], i + 1) || f(target, i + 1);
        memo[{target, i}] = res;
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        v = nums, n = (int) v.size();
        for (auto x: v) sum += x;
        if (sum & 1) {
            return false;   
        }
        int target = sum >> 1;
        return f(target, 0);
    }
};

// Another solution written on 09/07/2021
class Solution {
public:
    int target;
    bool ans = false;
    
    map<pair<int, int>, bool> memo;
    
    bool dp(vector<int>& v, int sum, int i, int n) {
        auto it = memo.find({sum, i});
        if (it != memo.end()) {
            return it->second;
        }
        if (sum > target) return false;
        if (sum == target) return true;
        if (i == n) return false;
        bool res = dp(v, sum, i + 1, n) || dp(v, sum + v[i], i + 1, n);
        memo[{sum, i}] = res;
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = (int) nums.size(), total = 0;
        for (int i = 0; i < n; ++i) total += nums[i];
        if (total % 2 != 0) return false;
        target = total / 2;
        return dp(nums, 0, 0, n);
    }
};
