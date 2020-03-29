class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int x = arr[0], cnt = 1, ans = -1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == x) cnt++;
            else {
                if (cnt == x) {
                    ans = x;   
                }
                cnt = 1;
                x = arr[i];
            }
        }
        if (cnt == x) ans = x;   
        
        return ans;
    }
};