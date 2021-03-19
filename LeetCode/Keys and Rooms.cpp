class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int) rooms.size();
        if (n == 0) return false;
        
        vector<bool> visit(n + 5, false);
        queue<int> qq;
        for (auto x: rooms[0]) qq.push(x);
        visit[0] = true;
        
        while (!qq.empty()) {
            auto key = qq.front(); qq.pop();
            // cout << "key -> " << key << endl;
            visit[key] = true;
            for (auto x: rooms[key]) {
                if (!visit[x]) qq.push(x);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                // cout << i << endl;
                return false;   
            }
        }
        
        return true;
    }
};
