class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = (int) A.size();
        vector<int> ans(n);
        int i = 0, j = n - 1;
        for (auto x: A) {
            if (x & 1) ans[j--] = x;
            else ans[i++] = x;
        }
        return ans;
    }
};