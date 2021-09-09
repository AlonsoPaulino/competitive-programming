class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = (int) s.size();
        for (int i = n - 2; i >= 0; --i) {
            shifts[i] += (shifts[i + 1] % 26);
        }
        for (int i = 0; i < n; ++i) {
            int x = (s[i] - 'a' + shifts[i]) % 26;
            s[i] = (char) (x + 'a');
        }
        return s;
    }
};
