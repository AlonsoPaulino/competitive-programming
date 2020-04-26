class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        queue< pair<int, int> > q;
        q.push(make_pair(0, 0));
        ans.push_back(nums[0][0]);
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            pair<int, int> d = make_pair(p.first + 1, p.second);
            pair<int, int> r = make_pair(p.first, p.second + 1);
            if (d.first < nums.size() && d.second < nums[d.first].size() && nums[d.first][d.second] != -1) {
                ans.push_back(nums[d.first][d.second]);
                q.push(d);
                nums[d.first][d.second] = -1;
            }
            if (r.first < nums.size() && r.second < nums[r.first].size() && nums[r.first][r.second] != -1) {
                ans.push_back(nums[r.first][r.second]);
                q.push(r);
                nums[r.first][r.second] = -1;
            }
        }
        return ans;
    }
};