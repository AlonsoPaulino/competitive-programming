class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = (int) pattern.size();
        vector<string> ans;
        for (auto w: words) {
            if (w.size() != n) continue;
            unordered_map<char, char> m1;
            unordered_map<char, char> m2;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                auto a = m1.find(pattern[i]);
                auto b = m2.find(w[i]);
                
                if (a == m1.end() && b != m2.end()) flag = false;
                else if (b == m2.end() && a != m1.end()) flag = false;
                else if (a != m1.end() && b != m2.end() 
                         && (a->second != w[i] || b->second != pattern[i])) flag = false;
                
                if (!flag) break;
                
                m1[pattern[i]] = w[i];
                m2[w[i]] = pattern[i];
            }
            if (flag) ans.push_back(w);
        }
        
        return ans;
    }
};
