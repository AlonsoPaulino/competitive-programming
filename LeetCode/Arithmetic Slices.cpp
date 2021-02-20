class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = (int) A.size();
        if (n == 0) return 0;
        
        int ans = 0, i = 0;
        while (i + 1 < n) {
            int x = i, y = i + 1, it = y + 1;
            int diff = A[y] - A[x];
            while (it < n && A[it] - A[it - 1] == diff) y = it++;
            
            int count = y - x + 1;
            
            if (count >= 3) {
                ans += (count - 2) * (count - 1) / 2;
                i = y + 1;
            } else {
                i = y;
            }
        }
        
        return ans;
    }
};
