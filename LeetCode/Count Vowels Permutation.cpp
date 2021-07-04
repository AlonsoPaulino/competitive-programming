const int MOD = 1e9 + 7;

int sum2(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int sum3(int a, int b, int c) {
    return sum2(sum2(a, b), c);
}

class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char, int> m;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
            } else {
                unordered_map<char, int> aux;
                aux['a'] = sum3(m['e'], m['i'], m['u']);
                aux['e'] = sum2(m['a'], m['i']);
                aux['i'] = sum2(m['e'], m['o']);
                aux['o'] = m['i'];
                aux['u'] = sum2(m['i'], m['o']);
                m['a'] = aux['a'];
                m['e'] = aux['e'];
                m['i'] = aux['i'];
                m['o'] = aux['o'];
                m['u'] = aux['u'];
            }
        }
        int ans = 0;
        for (auto it: m) {
            ans = sum2(ans, it.second);
        }
        return ans;
    }
};
