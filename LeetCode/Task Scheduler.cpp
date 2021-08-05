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

// Another solution written on 08/05/2021
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = (int) tasks.size(), ans = 0;
        vector<int> f(30);
        for (int i = 0; i < sz; ++i) {
            f[tasks[i] - 'A']++, ans++;
        }
        sort(f.rbegin(), f.rend());
        int idle_groups = f[0] - 1;
        int idle_time = idle_groups * n;
        
        for (int i = 1; i < 30 && idle_time > 0; ++i) {
            idle_time = max(0, idle_time - min(f[i], idle_groups)); 
        }
        
        ans += idle_time;
        return ans;
    }
};
