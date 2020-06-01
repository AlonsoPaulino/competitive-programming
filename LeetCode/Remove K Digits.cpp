class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = (int) num.size();
        int x = n - k;
        list<int> v;
        list<int>::iterator it;
        string aux, ans;
        for (int i = 0; i < n; ++i) v.push_back(i);
        v.sort([num](const int &a, const int &b) {
            return num[a] - '0' < num[b] - '0';
        });
        int lastIndex = -1;
        for (int i = 1; i <= x; ++i) {
            it = v.begin();
            while (it != v.end()) {
                int val = *it;
                if (val < lastIndex) {
                    list<int>::iterator tmp = next(it);
                    v.erase(it);
                    it = tmp;
                    continue;
                }
                if (val > lastIndex && x - i <= n - val - 1) {
                    v.erase(it);
                    aux += num[val];
                    lastIndex = val;
                    break;
                }
                ++it;
            }
        }
        int i = 0;
        while (i < x && aux[i] == '0') ++i;
        for (i; i < x; ++i) ans += aux[i];
        if (ans.size() == 0) ans = "0";
        return ans;
    }
};