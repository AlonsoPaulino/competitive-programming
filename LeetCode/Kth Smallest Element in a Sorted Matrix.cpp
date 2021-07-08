class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto v: matrix) {
            for (auto x: v) {
                pq.push(x);
            }
        }
        while (k > 1) {
            --k, pq.pop();
        }
        return pq.top();
    }
};
