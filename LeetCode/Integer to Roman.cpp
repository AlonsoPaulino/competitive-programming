class Solution {
public:    
    string intToRoman(int num) {
        unordered_map<int, string> m;
        m[1000] = "M", m[2000] = "MM", m[3000] = "MMM";
        m[100] = "C", m[200] = "CC", m[300] = "CCC";
        m[400] = "CD", m[500] = "D", m[600] = "DC", m[700] = "DCC", m[800] = "DCCC", m[900] = "CM";
        m[10] = "X", m[20] = "XX", m[30] = "XXX";
        m[40] = "XL", m[50] = "L", m[60] = "LX", m[70] = "LXX", m[80] = "LXXX", m[90] = "XC";
        m[1] = "I", m[2] = "II", m[3] = "III", m[4] = "IV", m[5] = "V"; 
        m[6] = "VI", m[7] = "VII", m[8] = "VIII", m[9] = "IX", m[10] = "X";
        
        string ans = "";
        int cnt = 1;
        
        while (num > 0) {
            int d = num % 10;
            ans = (m[cnt * d] + ans);
            cnt *= 10;
            num /= 10;
        }
        
        return ans;
    }
};
