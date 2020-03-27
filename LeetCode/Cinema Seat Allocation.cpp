class Solution {
public:
    bool exists(int x, vector<int> v) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == x) return true;
        }
        return false;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int l = reservedSeats.size();
        map<int, vector<int>> m;
        
        for (int i = 0; i < l; ++i) {
            m[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
    
        long ans = 0L;
        
        map<int, vector<int>>::iterator it = m.begin();
        
        while (it != m.end()) {
            // Case 1
            bool c1a = true, c1b = true, c2 = false;
            for (int i = 2; i <= 5 && c1a; ++i) {
                if (exists(i, it->second)) c1a = false;
            }
            for (int i = 6; i <= 9 && c1b; ++i) {
                if (exists(i, it->second)) c1b = false;
            }
            if (c1a) ans++;
            if (c1b) ans++;
            
            // Case 2
            if (!c1a && !c1b) {
                c2 = true;
                for (int i = 4; i <= 7 && c2; ++i) {
                    if (exists(i, it->second)) c2 = false;
                }
            }
            
            if (c2) ans++;
            
            ++it;
        }
        
        ans += ((n - m.size()) * 2);
        
        return ans;
    }
};