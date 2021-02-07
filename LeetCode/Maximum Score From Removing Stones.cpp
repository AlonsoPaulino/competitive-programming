class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v(3);
        v[0] = a, v[1] = b, v[2] = c;
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        
        for (int i = 0; i < v[0]; ++i) {
            if (v[2] > v[1]) v[2]--;
            else v[1]--;
            ans++;
        }
        
        ans += min(v[1], v[2]);
        return ans;
    }
};
