class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        vector<int> b(n);
        vector<int> ans(n);
        a[0] = nums[0], b[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            a[i] = nums[i] * a[i - 1];
            b[n - 1 - i] = nums[n - 1 - i] * b[n - i]; 
        }
        for (int i = 0; i < n; ++i) {
            int ia = i - 1, ib = i + 1;
            int x = 1, y = 1;
            if (ia >= 0) x = a[ia];
            if (ib < n) y = b[ib];
            ans[i] = x * y;
        }
        return ans;
    }
};

// Another solution written at 07/04/2021
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] *= nums[i + 1];
            nums[i] *= nums[i + 1];
        }
        return ans;
    }
};
