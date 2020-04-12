class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j) {
                    string a = words[i], b = words[j];
                    if (b.size() > a.size() && b.find(a) != -1) {
                        ans.insert(a);
                    }
                }
            }
        }
        vector<string> v(ans.size());
        copy(ans.begin(), ans.end(), v.begin());
        return v;
    }
};