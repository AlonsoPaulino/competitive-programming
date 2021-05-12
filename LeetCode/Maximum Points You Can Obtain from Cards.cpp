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

// Another solution written in May 11th
class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int n = (int) p.size();
        
        vector<int> v(2 * n);
        vector<int> s(2 * n);
        for (int i = 0; i < n; ++i) v[i] = p[i];
        for (int i = 0; i < n; ++i) v[n + i] = p[i];
        
        s[0] = v[0];
        for (int i = 1; i < 2 * n; ++i) s[i] = s[i - 1] + v[i];
        
        int ans = 0;
        
        for (int i = n - k; i <= n; ++i) {
            int a = i, b = i + k - 1;
            int sum = 0;
            if (a == 0) sum = s[b];
            else sum = s[b] - s[a - 1];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
