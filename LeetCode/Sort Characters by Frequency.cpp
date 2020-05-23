class Solution {
public:
    static bool cmp(pair<char, int> p1, pair<char, int> p2) {
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> m;
        unordered_map<char, int>::iterator it;
        vector< pair<char, int> > v;
        for (auto& x: s) m[x]++;
        for (it = m.begin(); it != m.end(); ++it) v.push_back({it->first, it->second});
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        for (auto& x : v) {
            for (int i = 0; i < x.second; ++i) ans += x.first; 
        }
        return ans;
    }
};