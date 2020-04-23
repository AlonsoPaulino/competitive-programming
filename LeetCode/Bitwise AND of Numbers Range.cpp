class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = n;
        while (x - 1 >= m) x &= x - 1;
        return x;
    }
};