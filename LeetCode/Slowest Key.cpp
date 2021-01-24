class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = (int) releaseTimes.size();
        
        int st = releaseTimes[0], lk = releaseTimes[0];
        char ans = keysPressed[0];
        
        for (int i = 1; i < n; ++i) {
            char key = keysPressed[i];
            int rt = releaseTimes[i];
            
            int dt = rt - st;
            
            if (dt > lk) {
                ans = key;
                lk = dt;
            } else if (dt == lk && key > ans) {
                ans = key;
            }
            
            st = rt;
        }
        
        return ans;
    }
};
