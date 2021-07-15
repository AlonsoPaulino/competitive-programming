class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> m;
        vector<pair<char, int>> v;
        for (int i = 0; i < order.size(); ++i) m[order[i]] = i;
        for (auto c: str) {
            auto it = m.find(c);
            if (it != m.end()) {
                v.push_back({c, it->second});
            } else {
                v.push_back({c, 500});
            }
        }
        sort(v.begin(), v.end(),  [](const pair<char, int> a, const pair<char, int> b){
            return a.second < b.second;
        });
        string ans;
        for (auto x: v) {
            ans += x.first;
        }
        return ans;
    }
};
