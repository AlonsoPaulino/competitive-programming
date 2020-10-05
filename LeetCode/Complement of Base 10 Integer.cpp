class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int x = 1;
        while (x <= N) x <<= 1;
        return (x - 1) - N;
    }
};