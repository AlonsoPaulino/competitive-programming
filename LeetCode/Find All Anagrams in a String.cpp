const int N = 26;

class Solution {
public:
    int to_int(char c) {
        return (int) (c - 'a');
    }
    
    bool check(vector<int> a, vector<int> b) {
        for (int i = 0; i < N; ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int ss = (int) s.size();
        int sp = (int) p.size();
        
        if (sp > ss) {
            return vector<int>();
        }
        
        vector<int> v(N + 5, 0);
        vector<int> box(N + 5, 0);
        vector<int> ans;
        
        for (auto c: p) v[to_int(c)]++;
        for (int i = 0; i < sp; ++i) {
            box[to_int(s[i])]++;
            if (check(box, v)) ans.push_back(0);
        }
        
        for (int i = sp; i < ss; ++i) {
            box[to_int(s[i - sp])]--;
            box[to_int(s[i])]++;
            if (check(box, v)) ans.push_back(i - sp + 1);
        }
        
        return ans;
    }
};

// Another solution written on 09/07/2021
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = (int) s.size(), m = (int) p.size();
        unordered_map<char, int> um;
        unordered_map<char, int> x;
        vector<int> ans;
        for (auto c: p) um[c]++;
        for (int i = 0; i < n; ++i) {
            x[s[i]]++;
            if (i >= m) {
                x[s[i - m]]--;
            }
            bool add = true;
            for (auto it: um) {
                if (it.second != x[it.first]) {
                    add = false;
                    break;
                }
            }
            if (add) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};
