class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = (int) pattern.size(), m = (int) str.size();
        vector<string> v; string aux;
        for (int i = 0; i < m; ++i) {
            if (str[i] != ' ') aux += str[i];
            if (str[i] == ' ' || i + 1 == m) {
                v.push_back(aux);
                aux = "";
            }
        }
        if (n != (int) v.size()) return false;
        unordered_map<char, vector<int>> ump;
        unordered_map<char, vector<int>>::iterator it;
        set<string> ss; int cnt = 0;
        for (int i = 0; i < n; ++i) ump[pattern[i]].push_back(i);
        for (it = ump.begin(); it != ump.end(); ++it) {
            set<string> tmp; string s;
            auto x = it->second;
            for (auto a: x) {
                s = v[a];
                tmp.insert(v[a]);   
            }
            if ((int) tmp.size() == 1) {
                ss.insert(s);
                if ((int) ss.size() != ++cnt) return false;
            } else return false;
        }
        return true;
    }
};