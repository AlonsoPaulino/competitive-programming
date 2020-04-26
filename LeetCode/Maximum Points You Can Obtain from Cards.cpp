class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int score = 0;
        for (int i = 1; i < n; ++i) {
            cardPoints[i] = cardPoints[i - 1] + cardPoints[i];
        }
        for (int i = 0; i < k; ++i) {
            score = max(score, cardPoints[i] + cardPoints[n - 1] - cardPoints[n - 1 - (k - i - 1)]);
        }
        if (n - 1 - k >= 0) {
            score = max(score, cardPoints[n - 1] - cardPoints[n - 1 - k]);   
        }
        return score;
    }
};