class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        map<string, vector<string> >::iterator it = m.begin();
        while (it != m.end()) {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};