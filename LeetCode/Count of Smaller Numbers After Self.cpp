typedef pair<int, int> pii;

class Solution {
    vector<int> ans;
    vector<pii> v;
public:
    void mergesort(int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergesort(lo, mid);
        mergesort(mid + 1, hi);
        
        vector<pii> tmp(hi - lo + 1);
        int i = lo, j = mid + 1, k = 0;
        int jumps = 0;        

        while (i <= mid && j <= hi) {
            if (v[i].first <= v[j].first) {
                ans[v[i].second] += jumps;
                tmp[k++] = v[i++];
            } else {
                jumps++;
                tmp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            ans[v[i].second] += jumps;
            tmp[k++] = v[i++];
        }
        while (j <= hi) {
            tmp[k++] = v[j++];
        }
        
        for (i = lo; i <= hi; ++i) {
            v[i] = tmp[i - lo];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = (int) nums.size();
        v = vector<pii>(n);
        ans = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            v[i] = { nums[i], i} ;
        }
        mergesort(0, n - 1);
        return ans;
    }
};
