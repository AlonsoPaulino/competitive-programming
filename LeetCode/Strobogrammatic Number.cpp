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

// Another solution written on 07/04/2021
class Solution {
public:
    bool check_1(int a) {
        return a == 1 || a == 0 || a == 8;
    }
    
    bool check_2(int a, int b) {
        if (a == b && check_1(a)) return true;
        if (a == 6 && b == 9) return true;
        return a == 9 && b == 6;
    }
    
    bool isStrobogrammatic(string num) {
        int n = (int) num.size();
        for (int i = 0; i < n / 2; ++i) {
            int j = n - i - 1;
            if (!check_2(num[i] - '0', num[j] - '0')) {
                return false;
            }    
        }
        if (n & 1) {
            int x = num[n / 2] - '0';
            return check_1(x);
        }
        return true;
    }
};

// Another solution written on 02/01/2021
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = (int) num.size();
        for (int i = 0; i <= n / 2; ++i) {
            char a = num[i], b = num[n - i - 1];
            if (a == '1' && b == '1') continue;
            if (a == '0' && b == '0') continue;
            if (a == '8' && b == '8') continue;
            if (a == '9' && b == '6') continue;
            if (a == '6' && b == '9') continue;
            return false;
        }
        return true;
    }
};
