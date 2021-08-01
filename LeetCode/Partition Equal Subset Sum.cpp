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
