class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v; map<char, int> m;
        for (auto x: tasks) m[x]++;
        for (auto it: m) v.push_back(it.second);
        sort(v.begin(), v.end());
        int sz = (int) v.size();
        int ans = (v[sz - 1] - 1) * n;
        for (int i = sz - 2; i >= 0; --i) {
            ans = ans - min(v[sz - 1] - 1, v[i]);
        }
        return max(ans, 0) + (int) (tasks.size());
    }
};