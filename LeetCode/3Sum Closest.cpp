#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"

class Solution {
    unordered_map<int, set<int>> m; 
    vector<int> v;
    int n;
public:    
    int solve(int i, int j, int k) {
        auto x = lower_bound(v.begin(), v.end(), k) - v.begin();
        if (x < 0 || x >= n) x = -1;
        if (x != -1 && x != i && x != j && v[x] == k) {
            return v[i] + v[j] + k;
        }
        int p = x == -1 ? n - 1 : x;
        int a = p, b = p;
        while (a == i || a == j) --a;
        while (b == i || b == j) ++b;
        
        if (a >= 0 && b < n) {
            if (abs(k - v[a]) < abs(k - v[b])) {
                return v[i] + v[j] + v[a];
            } else {
                return v[i] + v[j] + v[b];
            }
        } else if (a >= 0) {
            return v[i] + v[j] + v[a];
        } else {
            return v[i] + v[j] + v[b];
        }
        
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        n = (int) nums.size();
        sort(nums.begin(), nums.end()), v = nums;
        int ans = 1000000;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = solve(i, j, target - (v[i] + v[j]));
                int b = solve(i, j, v[i] + v[j] - target);
                if (abs(target - a) < abs(target - ans)) ans = a;
                if (abs(target - b) < abs(target - ans)) ans = b;
            }
        }
        
        return ans;
    }
};
