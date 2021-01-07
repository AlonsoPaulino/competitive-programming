class Solution {
    unordered_map<string, vector<pair<string, int>>> m;
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = (int) website.size();
        for (int i = 0; i < n; ++i) {
            string u = username[i];
            string w = website[i];
            int t = timestamp[i];
            m[u].push_back({w, t});
        }
        
        for (auto it: m) {
            vector<pair<string, int>> v = it.second;
            sort(v.begin(), v.end(), [](pair<string, int> const a, pair<string, int> const b) {
                if (a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
            m[it.first] = v;
        }
        
        vector<string> ans(3, "");
        int visit = -1;
        
        for (auto it: m) {
            string user = it.first;
            vector<pair<string, int>> v = it.second;

            int s = (int) v.size();
            for (int i = 0; i + 2 < s; ++i) {
                for (int j = i + 1; j + 1 < s; ++j) {
                    for (int k = j + 1; k < s; ++k) {
                        string a = v[i].first, b = v[j].first, c = v[k].first;
                        int cnt = solve(user, a, b, c);
                        
                        if (cnt > visit || visit == -1) {
                            ans[0] = a, ans[1] = b, ans[2] = c;
                            visit = cnt;
                        } else if (cnt == visit) {
                            if (validate(ans, a, b, c)) {
                                ans[0] = a, ans[1] = b, ans[2] = c;   
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    bool validate(vector<string> v, string a, string b, string c) {
        if (a < v[0]) return true;
        if (a == v[0] && b < v[1]) return true;
        if (a == v[0] && b == v[1] && c < v[2]) return true;
        return false;
    }
    
    int solve(string user, string a, string b, string c) {
        int cnt = 1;
        for (auto it: m) {
            if (it.first != user) {
                vector<pair<string, int>> v = it.second;
                int n = (int) v.size(), i = 0;
                while (i < n && v[i].first != a) ++i; ++i;
                while (i < n && v[i].first != b) ++i; ++i;
                while (i < n && v[i].first != c) ++i;
                
                if (i < n && v[i].first == c) ++cnt;
            }
        }
        return cnt;
    }
};