class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = (int) arr.size();
        vector<int> moves(n + 5, 0);
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                moves[i] = i > 0 ? moves[i - 1] + 1 : 1;
            } else {
                moves[i] = i > 0 ? moves[i - 1] : 0;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            int x = moves[i - 1];
            if (x > 0) {
                if (i + x < n) {
                    arr[i + x] = arr[i];
                }
                arr[i] = 0;
            }
        }
    }
};
