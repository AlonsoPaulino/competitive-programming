class Solution {
public:
    vector<string> split_space(string s) {
        vector<string> res;
        string tmp = "";
        for (auto c: s) if (c == ' ') {
            res.push_back(tmp); tmp = "";
        } else tmp += c;
        if (tmp.size() > 0) res.push_back(tmp);
        return res;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        unordered_map<string, vector<string>>::iterator it;
        for (auto x: paths) {
            auto v = split_space(x);
            string path = v[0];
            for (int i = 1; i < v.size(); ++i) {
                string f_name = "", content = "";
                int j = 0, in = v[i].size();
                while (j < in && v[i][j] != '(') f_name += v[i][j], ++j;
                ++j; while (j < in && v[i][j] != ')') content += v[i][j], ++j;
                m[content].push_back(path + "/" + f_name);
            }
        }
        vector<vector<string>> ans;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() > 1) {
                ans.push_back(it->second);   
            }
        }
        return ans;
    }
};
