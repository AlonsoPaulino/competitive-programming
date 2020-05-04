class Solution {
public:
    long findComplement(long num) {
        long x = log2(num);
        long y = (long) (1 << (x + 1)) - 1;
        return num ^ y;
    }
};