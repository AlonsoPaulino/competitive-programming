class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        priority_queue<int> pq;
        for (auto x: arr) m[x]++;
        for (auto it: m) pq.push(it.second);
        int n = (int) arr.size();
        int acum = 0, total = 0;
        while (acum < n / 2) {
            acum += pq.top(); pq.pop();
            total++;
        }
        return total;
    }
};
