class Solution {
    const int INF = 1e9;
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 0;
        int sqi = squirrel[0], sqj = squirrel[1];
        int tri = tree[0], trj = tree[1];
        
        int diff = -INF;
        
        for (auto x: nuts) {
            int nui = x[0], nuj = x[1];
            int tr_distance = abs(tri - nui) + abs(trj - nuj);
            int sq_distance = abs(sqi - nui) + abs(sqj - nuj);
            ans += 2 * tr_distance;
            diff = max(diff, tr_distance - sq_distance);
        }
        
        return ans - diff;
    }
};
