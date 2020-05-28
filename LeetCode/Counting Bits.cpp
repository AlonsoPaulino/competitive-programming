class Solution {
public:
    int bitCnt(int num) {
        if (num == 0) return 0;
        int cnt = 0;
        while (num > 0) {
            num = num & (num - 1);
            ++cnt;
        }
        return cnt;
    }
    
    vector<int> countBits(int num) {
        vector<int> v;
        for (int i = 0; i <= num; ++i) {
            v.push_back(bitCnt(i));
        }
        return v;
    }
};