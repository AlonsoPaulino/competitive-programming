class Solution {
    unordered_map<char, char> eq;
public:
    bool exists(char x) {
        return eq.find(x) != eq.end();
    }
    
    bool isStrobogrammatic(string num) {
        eq['9'] = '6', eq['6'] = '9', eq['0'] = '0', eq['8'] = '8', eq['1'] = '1';
        
        int n = (int) num.size();
        for (int i = 0; i < n / 2; ++i) {
            char a = num[i], b = num[n - i - 1];
            if (!exists(a) || !exists(b) || eq[a] != b) {
                return false;
            }
        }
        
        if (n & 1) {
            if (!exists(num[n / 2])) {
                return false;   
            }
            return eq[num[n / 2]] == num[n / 2];
        }
        
        return true;
    }
};
