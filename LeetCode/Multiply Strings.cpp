class Solution {
public:
    string validate(string s) {
        int n = (int) s.size();
        if (n == 0) {
            return "0";
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    string sum(string a, string b) {
        int na = (int) a.size(), nb = (int) b.size();
        int i = na - 1, j = nb - 1, carry = 0;
        string s = "";
        while (i >= 0 || j >= 0) {
            int x = 0, y = 0;
            if (i >= 0) x = a[i--] - '0';
            if (j >= 0) y = b[j--] - '0';
            int sum = x + y + carry;
            carry = sum / 10;
            char c = (sum % 10) + '0';
            s += c;
        }
        if (carry > 0) s += (carry + '0');
        return validate(s);
    }
    
    string multiply(string a, string b) {
        int na = (int) a.size(), nb = (int) b.size();
        if (a == "0" || b == "0") {
            return "0";
        }
        if (a == "1") return b;
        if (b == "1") return a;
        int cnt = 0;
        string result = "0";
        for (int i = na - 1; i >= 0; --i) {
            int x = a[i] - '0', carry = 0;
            string s = "";
            for (int j = nb - 1; j >= 0; --j) {
                int y = b[j] - '0';
                int mul = x * y + carry;
                carry = mul / 10;
                char c = (mul % 10) + '0';
                s += c;
            }
            if (carry > 0) s += (carry + '0');
            s = validate(s);
            for (int k = 0; k < cnt; ++k) {
                s += '0';
            }
            result = sum(result, s);
            ++cnt;
        }
        return result;
    }
};
