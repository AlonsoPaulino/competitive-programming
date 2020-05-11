class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector< set<int> > x(N + 5);
        vector< set<int> > y(N + 5);
        
        for (auto& v: trust) {
            x[v[0]].insert(v[1]);
            y[v[1]].insert(v[0]);
        }
        
        for (int i = 1; i <= N; ++i) {
            if (x[i].size() == 0 && y[i].size() == N - 1) return i;
        }
        
        return -1;
    }
};