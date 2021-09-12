class Solution {
public:
    unordered_map<int, string> m;
    
    string three(int num) {
        int cent = num / 100;
        string a = m[cent];
        string b = two(num % 100);
        if (b.size() > 0) {
            return a + " Hundred " + b;
        }
        return a + " Hundred";
    }
    
    string two(int num) {
        if (num >= 20) {
            int dec = num / 10;
            string a = m[dec * 10];
            string b = m[num % 10];
            if (b.size() > 0) {
                return a + " " + b;
            }
            return a;
        }
        return m[num];
    }
    
    string group(int num) {
        int nd = num > 0 ? log10(num) + 1 : 0;
        if (nd == 3) return three(num);
        else if (nd == 2) return two(num);
        else return m[num];
    }
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        m[1] = "One", m[2] = "Two", m[3] = "Three", m[4] = "Four", m[5] = "Five", m[6] = "Six", m[7] = "Seven";
        m[8] = "Eight", m[9] = "Nine", m[10] = "Ten", m[11] = "Eleven", m[12] = "Twelve", m[13] = "Thirteen";
        m[14] = "Fourteen", m[15] = "Fifteen", m[16] = "Sixteen", m[17] = "Seventeen", m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty", m[30] = "Thirty", m[40] = "Forty", m[50] = "Fifty", m[60] = "Sixty", m[70] = "Seventy";
        m[80] = "Eighty", m[90] = "Ninety";
        stack<int> st;
        while (num > 0) {
            int cnt = 0, x = 0, mul = 1;
            while (num > 0 && cnt < 3) {
                x += ((num % 10) * mul);
                num /= 10;
                ++cnt, mul *= 10;
            }
            st.push(x);
        }
        string ans = "";
        while (!st.empty()) {
            int n = (int) st.size();
            int x = st.top(); st.pop();
            
            string g = group(x);
            string c = "", res = "";
            
            if (g.size() > 0) {
                if (n == 4) c = "Billion";
                else if (n == 3) c = "Million";
                else if (n == 2) c = "Thousand";   
                res = g;
                if (c.size() > 0) res += " ";
                res += c;
            }
            
            if (res.size() > 0) {
                if (ans.size() > 0) {
                    ans += " ";   
                }
                ans += res;
            }
        }
        return ans;
    }
};
