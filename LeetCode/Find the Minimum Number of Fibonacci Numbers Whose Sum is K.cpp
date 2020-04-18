class Solution {
public:
    int fb[100000];
    
    int solve(int x) {
        if (x == 0) return 0;
        int i = 0;
        while (i + 1 < 100000 && fb[i + 1] <= x) ++i;
        int y = x - fb[i];
        return solve(y) + 1;
    }
    
    int findMinFibonacciNumbers(int k) {
        if (fb[0] != 1) {
            fb[0] = 1, fb[1] = 1;
            for (int i = 2; fb[i - 1] + fb[i + 1] < 1000000000; ++i) {
                fb[i] = fb[i-2] + fb[i - 1];
            }   
        }
        return solve(k);
    }
};