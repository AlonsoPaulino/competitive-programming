class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        unordered_map<char, int> m;
        int ans = 0;
        int n = (int) S.size();
    
        
        for (int i = 0; i < K && i < n; ++i) {
            m[S[i]]++;
            if (m.size() == K) ++ans;
        }
        
        for (int i = K; i < n; ++i) {
            m[S[i - K]]--;
            if (m[S[i - K]] == 0) {
                m.erase(S[i - K]);
            }
            m[S[i]]++;
            if (m.size() == K) ++ans;
        }
        
        return ans;
    }
};
