class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &x: stones) pq.push(x);
        
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y - x);
            }
        }
        
        if (pq.size() == 1) return pq.top();
        return 0;
    }
};