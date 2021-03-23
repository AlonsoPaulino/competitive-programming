class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> pw;
        if (N == 1) pw.push_back(1);
        int a = 1, d = log10(N) + 1;
        while (true) {
            int dd = log10(a * 2) + 1;
            if (dd == d) pw.push_back(a * 2);
            else if (dd > d) break;
            a *= 2;
        }
        int sz = (int) pw.size();
        vector<int> nv(10, 0);
        while (N > 0) {
            nv[N % 10]++;
            N /= 10;
        }
        vector<vector<int>> v(sz, vector<int>(10, 0));
        for (int i = 0; i < sz; ++i) {
            int x = pw[i];
            while (x > 0) {
                v[i][x % 10]++;
                x /= 10;
            }
            bool equal = true;
            for (int j = 0; j < 10; ++j) {
                if (nv[j] != v[i][j]) {
                    equal = false;
                    break;
                }
            }
            if (equal) return true;
        }
        
        return false;
    }
};
