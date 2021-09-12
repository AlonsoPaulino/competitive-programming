const int N = 10005;

class Solution {
public:
    vector<int> g;
    
    void join(int x, int y) {
        g[find(x)] = find(y);
    }
    
    int find(int x) {
        return (x == g[x]) ? x : g[x] = find(g[x]);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = (int) accounts.size();
        unordered_map<string, int> hash;
        unordered_map<int, string> rtable;
        int hash_code = 1;
        g = vector<int>(N, 0);
        
        for (int i = 0; i < N; ++i) g[i] = i;
        
        for (int i = 0; i < n; ++i) {
            int sz = (int) accounts[i].size();
            for (int j = 1; j < sz; ++j) {
                auto it = hash.find(accounts[i][j]);
                if (it == hash.end()) {
                    hash[accounts[i][j]] = hash_code;
                    rtable[hash_code] = accounts[i][j];
                    ++hash_code;
                }
                if (j >= 2) {
                    join(hash[accounts[i][j]], hash[accounts[i][j - 1]]);
                }
            }
        }
        
        vector<vector<string>> ans;    
        set<int> seen;
        
        for (int i = 0; i < n; ++i) {
            auto acc = accounts[i];
            if (seen.find(find(hash[acc[1]])) != seen.end()) {
                continue;
            }
            vector<string> res;
            for (int i = 0; i < N; ++i) {
                if (find(i) == find(hash[acc[1]])) {
                    res.push_back(rtable[i]);
                    seen.insert(find(i));
                }
            }
            sort(res.begin(), res.end());
            res.insert(res.begin(), acc[0]);
            ans.push_back(res);
        }
        
        return ans;
    }
};
