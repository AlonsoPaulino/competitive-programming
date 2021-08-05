class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (auto p: people) {
            ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};

// Another solution written on 08/05/2021
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int> &b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int n = (int) people.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            auto x = people[i];
            ans.insert(ans.begin() + x[1], x);
        }
        return ans;
    }
};
