/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int n = d[0], m = d[1];
        int ans = m - 1;
        int x = n - 1;
        if (n + m > 0) {
            for (int i = 0; i < n; ++i) {
                while (ans - 1 >= 0 && binaryMatrix.get(i, ans - 1) == 1) ans--, x = i;
            }
        }
        if (binaryMatrix.get(x, ans) == 1) return ans;
        return -1;
    }
};