class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        vector<int> nk;
        while (k > 0) {
            nk.push_back(k % 10);
            k /= 10;
        }
        int n = num.size(), m = nk.size();
        int carry = 0;
        for (int i = n - 1, j = 0; i >= 0 || j < m; --i, ++j) {
            int sum = carry;
            if (i >= 0) sum += num[i];
            if (j < m) sum += nk[j];
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
