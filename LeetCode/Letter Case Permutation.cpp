class Solution {
    int n = 0;
    string x = "";
    vector<string> ans;
public:
    void generate_all_permutations(string s, int l) {
        if (l == n) {
            ans.push_back(s);
            return;
        }
        
        generate_all_permutations(s + string(1, x[l]), l + 1);
        
        if (x[l] >= 'a' && x[l] <= 'z') {
            generate_all_permutations(s + string(1, toupper(x[l])), l + 1);
        } else if (x[l] >= 'A' && x[l] <= 'Z') {   
            generate_all_permutations(s + string(1, tolower(x[l])), l + 1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        n = (int) S.size(), x = S;
        if (n == 0) return ans;

        generate_all_permutations("", 0);
        return ans;
    }
};
