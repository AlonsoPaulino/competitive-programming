class Solution {
public:
    pair<int, int> add(char a, char b, int carry) {
        int na = a - '0', nb = b - '0';
        int sum = na + nb + carry;
        if (sum == 0) return {0, 0};
        if (sum == 1) return {1, 0};
        if (sum == 2) return {0, 1};
        return {1, 1};
    }
    
    string addBinary(string a, string b) {
        int na = (int) a.size(), nb = (int) b.size();
        int i = na - 1, j = nb - 1, carry = 0;
        string s = "";
        while (i >= 0 || j >= 0) {
            char x = '0', y = '0';
            if (i >= 0) x = a[i--];
            if (j >= 0) y = b[j--];
            auto sum = add(x, y, carry);
            s += (sum.first + '0');
            carry = sum.second;
        }
        if (carry != 0) s += '1';
        if (s.size() == 0) return "0";
        reverse(s.begin(), s.end());
        return s;
    }
};
