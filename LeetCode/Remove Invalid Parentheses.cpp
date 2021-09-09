class Solution {
public:    
    vector<string> removeInvalidParentheses(string s) {
        int n = (int) s.size();
        int total = 1 << n;
        int min_del = INT_MAX;
        set<string> st;
        for (int mask = 0; mask < total; ++mask) {
            int x = mask;
            bool is_valid = true;
            for (int i = n - 1; i >= 0; --i) {
                if ((1 << i) & mask) {
                    if (s[i] != ')' && s[i] != '(') {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (!is_valid) {
                continue;
            }
            int cnt = 0, del = 0;
            for (int i = n - 1; i >= 0; --i) {
                if ((1 << i) & mask) {
                    ++del; continue;
                }
                if (s[i] == ')') {
                    ++cnt;
                } else if (s[i] == '(') {
                    if (cnt == 0) {
                        cnt = -1;
                        break;
                    }
                    cnt = cnt - 1;
                }
            }
            if (cnt == 0) {
                if (del < min_del) {
                    min_del = del;
                    st.clear();
                }
                if (del == min_del) {
                    string x = "";
                    for (int i = n - 1; i >= 0; --i) {
                        if ((1 << i) & mask) continue;
                        x += s[i];
                    }
                    st.insert(x);
                }
            }
        }
        vector<string> ans;
        for (auto x: st) {
            reverse(x.begin(), x.end());
            ans.push_back(x);
        }
        return ans;
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    set<string> st;
    string s;
    int n;
    
    pair<int, int> valid_p(string x) {
        int sz = (int) x.size();
        int left = 0, right = 0;
        for (int i = 0; i < sz; ++i) {
            if (x[i] == '(') left++;
            else if (x[i] == ')') {
                if (left > 0) {
                    --left;   
                } else {
                    ++right;         
                }
            }
        }
        return {left, right};
    }
    
    void f(int left, int right, int i) {
        if (left < 0 || right < 0) return;
        if (left == 0 && right == 0) {
            // cout << s << endl;
            int cnt = 0;
            auto valid = valid_p(s);
            if (valid.first == 0 && valid.second == 0) {
                string add_word = "";
                for (auto c: s) if (c != '$') add_word += c;
                st.insert(add_word);
            }
            return;
        }
        if (i < n) {
            char c = s[i];
            if (c == '(' && left > 0) {
                s[i] = '$';
                f(left - 1, right, i + 1);
                s[i] = '(';
            } else if (c == ')' && right > 0) {
                s[i] = '$';
                // cout << "right : " << s << endl;
                f(left, right - 1, i + 1);
                s[i] = ')';
            }
            f(left, right, i + 1);
        }
    }
    
    vector<string> removeInvalidParentheses(string word) {
        n = (int) word.size(); s = word;
        auto valid = valid_p(s);
        f(valid.first, valid.second, 0);
        return vector<string>(st.begin(), st.end());
    }
};
