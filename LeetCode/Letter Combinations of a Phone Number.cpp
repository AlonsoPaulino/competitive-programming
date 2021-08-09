class Solution {
public:
    vector<string> ans;
    unordered_map<char, vector<char>> m;
    string d;
    int n;
    
    void solve(string s, int pos) {
        if (pos >= n) {
            if ((int) s.size() > 0) {
                ans.push_back(s);   
            }
            return;
        }
        for (auto c: m[d[pos]]) {
            string x = s;
            x += c;
            solve(x, pos + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        d = digits, n = (int) d.size();
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        solve("", 0);
        return ans;
    }
};
