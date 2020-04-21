class Solution {
public:
    int solve(vector<int> v, int target) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int pivot = l + (r - l) / 2;
            if (v[pivot] == target) return pivot;
            else {
                if (v[pivot] >= v[l]) {
                    if (target >= v[l] && target < v[pivot]) r = pivot - 1;
                    else l = pivot + 1;
                } else {
                    if (target <= v[r] && target > v[pivot]) l = pivot + 1;
                    else r = pivot - 1;
                }
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        return solve(nums, target);
    }
};