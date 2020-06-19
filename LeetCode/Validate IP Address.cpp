class Solution {
public:
    vector<string> split(string s, char c) {
        vector<string> v;
        int n = (int) s.size();
        string aux;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                v.push_back(aux);
                aux.clear();
                continue;
            }
            aux += s[i];
        }
        if (aux.size() > 0 || (s.size() > 0 && s[n - 1] == c)) v.push_back(aux);
        return v;
    }
    
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool isIpv4(string ip) {
        vector<string> v = split(ip, '.');
        if (v.size() == 4) {
            for (auto x: v) {
                int l = (int) x.size();
                if (l > 3 || l < 1) return false;
                if (x[0] == '0' && l > 1) return false;
                int num = 0;
                int mul = 1;
                for (int i = l - 1; i >= 0; --i) {
                    if (x[i] < '0' || x[i] > '9') return false;
                    num += (x[i] - '0') * mul;
                    mul *= 10;
                }
                if (num > 255) return false;
            }
            return true;
        }
        return false;
    }
    
    bool isIpv6(string ip) {
        vector<string> v = split(ip, ':');
        if (v.size() == 8) {
            for (auto x: v) {
                int l  = (int) x.size();
                if (l > 4 || l < 1) return false;
                for (int i = 0; i < l; ++i) {
                    if (!isNumber(x[i])) {
                        char c = toupper(x[i]);
                        if (c < 'A' || c > 'F') return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
    
    string validIPAddress(string IP) {
        if (isIpv4(IP)) return "IPv4";
        if (isIpv6(IP)) return "IPv6";
        return "Neither";
    }
};