class Solution {
public:
    int to_bit(string s) {
        int res = 0;
        for (auto x: s) {
            res |= (1 << (x - 'a'));
        }
        return res;
    }
    
    bool diff(int a, int b) {
        return (a & b) == 0;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;
        vector<int> bits(n);
        
        for (int i = 0; i < n; ++i) bits[i] = to_bit(words[i]);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (diff(bits[i], bits[j])) {
                    int a = (int) words[i].size();
                    int b = (int) words[j].size();
                    ans = max(ans, a * b);
                }   
            }
        }
        
        return ans;
    }
};
