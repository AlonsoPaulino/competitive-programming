class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        auto ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n = (int) arr.size();
        vector<int> ans;
        
        if (lb < n && arr[lb] <= x) {
            while (lb + 1 < n && arr[lb + 1] == arr[lb]) lb++;   
        } else lb = lb - 1;
        
        while (k--) {
            if (lb >= 0 && ub < n) {
                if (lb == ub) {
                    ans.push_back(arr[lb]);
                    --lb, ++ub;
                } else if (abs(arr[lb] - x) <= abs(arr[ub] - x)) {
                    ans.push_back(arr[lb--]);
                } else {
                    ans.push_back(arr[ub++]);
                }
            } else if (lb < 0) {
                ans.push_back(arr[ub++]);   
            } else if (ub + 1 > n) {
                ans.push_back(arr[lb--]);   
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
