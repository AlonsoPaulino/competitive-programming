class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, n = (int) height.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int w = abs(j - i);
            int h = min(height[i], height[j]);
            ans = max(ans, w * h);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
