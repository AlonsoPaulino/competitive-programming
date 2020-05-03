class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        unordered_map<string, string>::iterator it;
        int n = (int) paths.size();
        for (int i = 0; i < n; ++i) {
            vector<string> v = paths[i];
            m[v[0]] = v[1];
        }
        string dest = m.begin()->first;

        while (m.find(dest) != m.end()) {
            dest = m[dest];
        }

        return dest;
    }
};