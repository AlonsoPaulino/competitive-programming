class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int) arr.size();
        if (n <= 2) return false;
        int i = 1, cnti = 0, cntd = 0;
        while (i < n && arr[i] > arr[i - 1]) ++i, ++cnti;
        while (i < n && arr[i] < arr[i - 1]) ++i, ++cntd;
        return cnti > 0 && cntd > 0 && i == n;
    }
};
