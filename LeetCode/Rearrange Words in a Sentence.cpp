class Solution {
public:
    string arrangeWords(string text) {
        transform(text.begin(), text.end(), text.begin(), ::tolower); 
        string aux = "";
        map<int, vector<string> > m;
        for (auto&c : text) {
            if (c == ' ') {
                m[aux.size()].push_back(aux);
                aux = "";
            } else {
                aux += c;
            }
        }
        m[aux.size()].push_back(aux);
        string ans = "";
        map<int, vector<string> >::iterator it = m.begin();
        bool add = false;
        while (it != m.end()) {
            vector<string> v = it->second;
            for (auto& s: v) {
                if (add) ans += " "; else add = true;
                ans += s;
            }
            ++it;
        }
        if (ans.size() > 0) ans[0] = toupper(ans[0]);
        return ans;
    }
};