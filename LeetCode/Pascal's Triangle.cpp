class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; ++i) {
            vector<int> v;
            if (i == 0) {
                v = vector<int>(1, 1);
            } else {
                v = vector<int>(i + 1, 1);
                for (int k = 1; k <= i / 2; ++k) {
                    v[k] = v[i - k] = ans[i - 1][k - 1] + ans[i - 1][k];
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};
