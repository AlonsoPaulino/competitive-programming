class Solution {
    vector<int> v;
public:
    void mergesort(int lo, int hi) {
        if (lo >= hi) return;
        
        int mid = lo + (hi - lo) / 2;
        mergesort(lo, mid);
        mergesort(mid + 1, hi);
        
        vector<int> tmp(hi - lo + 1);
        int i = lo, j = mid + 1, k = 0;
        
        while (i <= mid && j <= hi) {
            if (v[i] <= v[j]) tmp[k++] = v[i++];
            else tmp[k++] = v[j++];
        }
        while (i <= mid) tmp[k++] = v[i++];
        while (j <= hi) tmp[k++] = v[j++];
        
        for (i = lo; i <= hi; ++i) {
            v[i] = tmp[i - lo];
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = (int) nums.size();
        v = nums;
        mergesort(0, n - 1);
        return v;
    }
};
