class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        int n = (int) paragraph.size();
        string aux = "";
        for (int i = 0; i < n; ++i) {
            char &c = paragraph[i];
            c = tolower(c);
            if (c >= 'a' && c <= 'z') {
                aux += c;
            } else if ((int) aux.size() > 0) {
                m[aux]++;
                aux = "";
            }
        }
        if ((int) aux.size() > 0) m[aux]++;
        for (auto x: banned) m.erase(x);
        string ans = "";
        int cnt = 0;
        for (auto it: m) {
            if (it.second > cnt) {
                ans = it.first;
                cnt = it.second;
            }
        }
        return ans;
    }
};