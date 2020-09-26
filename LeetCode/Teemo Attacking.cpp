class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int aux = 0, acum = 0;
        for (auto x: timeSeries) {
            int a = x + duration;
            acum += (a - max(aux, x));
            aux = a;
        }
        return acum;
    }
};`