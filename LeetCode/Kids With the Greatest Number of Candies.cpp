class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int aux = candies[0];
        vector<bool> ans;
        for (auto &x : candies) aux = max(aux, x);
        for (auto &x : candies) {
            ans.push_back(x + extraCandies >= aux);
        }
        return ans;
    }
};