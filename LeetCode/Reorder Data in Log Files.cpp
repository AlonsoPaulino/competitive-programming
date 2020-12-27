class Solution {
public:
    static string vector_to_string(vector<string> v) {
        string s = "";
        int n = (int) v.size();
        for (int i = 0; i < n; ++i) {
            s += v[i];
            if (i + 1 < n) s += " ";
        }
        return s;
    }
    
    static vector<string> split(string s, char c) {
        vector<string> v;
        string word = "";
        for (char x: s) {
            if (x != c) word += x;
            else if ((int) word.size() > 0) {
                v.push_back(word);
                word = "";
            }
        }
        if ((int) word.size() > 0) {
            v.push_back(word);
        }
        return v;
    }
    
    static bool is_letter_log(vector<string> v) {
        return v[1][0] >= 'a' && v[1][0] <= 'z';
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<vector<string>> ll, dd;
        for (string x: logs) {
            vector<string> v = split(x, ' ');
            if (is_letter_log(v)) ll.push_back(v);
            else dd.push_back(v);
        }
        sort(ll.begin(), ll.end(), [](vector<string>& a, vector<string>& b) {
            string sa = vector_to_string({a.begin() + 1, a.end()});
            string sb = vector_to_string({b.begin() + 1, b.end()});
            if (sa == sb) {
                return a[0] < b[0];
            }
            return sa < sb;
        });
        
        vector<string> ans;
        for (auto x: ll) {
            ans.push_back(vector_to_string(x));
        }
        for (auto x: dd) {
            ans.push_back(vector_to_string(x));
        }
        return ans;
    }
};