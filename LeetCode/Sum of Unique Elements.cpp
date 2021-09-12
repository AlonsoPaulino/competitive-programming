class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x: nums) m[x]++;
        int sum = 0;
        for (auto it: m) {
            if (it.second < 2) sum += it.first;
        }
        return sum;
    }
};
