class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        map<string, unordered_map<int, int> > m;
        int n = favoriteCompanies.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < favoriteCompanies[i].size(); ++j) {
                string s = favoriteCompanies[i][j];
                m[s][i] = 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            bool inc = true;
            for (int k = 0; k < n && inc; ++k) {
                if (i != k && favoriteCompanies[k].size() > favoriteCompanies[i].size()) {
                    bool aux = true;
                    for (int j = 0; j < favoriteCompanies[i].size() && aux; ++j) {
                        string company = favoriteCompanies[i][j];
                        if (m[company][k] != 1) aux = false;
                    }
                    if (aux) inc = false;
                }
            }
            if (inc) ans.push_back(i);
        }
        
        return ans;
    }
};