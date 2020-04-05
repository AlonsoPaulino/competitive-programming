class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s.size() != 1) {
            if (s[s.size() - 1] == '1') {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') s[i--] = '0';
                if (i < 0) s.insert(0, "1"); else s[i] = '1';
            } else {
                s.erase(s.size() - 1, 1);
            }
            ++steps;
        }
        return steps;
    }
};