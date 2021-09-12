class Solution {
public:
    vector<vector<int>> ans;
    
    void f(int pos, vector<int> &v, int &n) {
        if (pos == n) {
            ans.push_back(v);
            return;
        }
        for (int i = pos; i < n; ++i) {
            swap(v[i], v[pos]);
            f(pos + 1, v, n);
            swap(v[pos], v[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int) nums.size();
        f(0, nums, n);
        return ans;
    }
};
