class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int k = (int) target.size();
        int j = 0;
        for (int i = 1; j < k && i <= n; ++i) {
            if (target[j] == i) {
                ans.push_back("Push");
                ++j;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};