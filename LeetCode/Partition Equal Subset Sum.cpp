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
    int target, n;
    vector<int> v;
    bool ans = false;
    
    map<pair<int, int>, bool> memo;
    
    bool dp(int sum, int i) {
        auto it = memo.find({sum, i});
        if (it != memo.end()) {
            return it->second;
        }
        if (sum == target) return true;
        if (sum > target || i == n) return false;
        
        bool res =  dp(sum + v[i], i + 1) || dp(sum, i + 1);
        memo[{sum, i}] = res;
        
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        v = nums, n = (int) nums.size();
        int total = 0; for (auto x: nums) total += x;
        if (total % 2 != 0) return false;
        target = total / 2;
        return dp(0, 0);
    }
};
