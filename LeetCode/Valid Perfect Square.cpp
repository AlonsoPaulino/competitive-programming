class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = 1;
        while (x * x < num) ++x;
        return x * x == num;
    }
};