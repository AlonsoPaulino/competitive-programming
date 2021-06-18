class NumArray {
    vector<int> bit;
public:
    NumArray(vector<int>& nums) {
        int n = (int) nums.size();
        bit = vector<int>(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int i = index + 1;
        int a = read(i), b = read(i - 1);
        int add = val - (a - b);
        while (i < (int) bit.size()) {
            bit[i] += add;
            i += (i & -i);
        }
    }
    
    int read(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return read(right + 1) - read(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
