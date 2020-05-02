class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int ai = -1, bi = -1;
        int n = (int) digits.size();
        int ax = 9, bx = 0;
        for (int i = 0; i < n; ++i) {
            if (ai == -1 && (digits[i] < 9 || i == n - 1)) {
                ai = digits[i];
            }
            if (bi == -1 && ((digits[i] > 1 && i == 0) || (i > 0 && digits[i] > 0 && digits[i] != digits[0]) || i == n - 1)) {
                if (i == 0) bx = 1;
                bi = digits[i];
            }
        }
        int a = 0, b = 0;
        int acum = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == ai) {
                a += (ax * acum);
            } else {
                a += (digits[i] * acum);
            }
            if (digits[i] == bi) {
                b += (bx * acum);
            } else {
                b += (digits[i] * acum);
            }
            acum *= 10;
        }
        return a - b;
    }
};