// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int ans = -1;
        while (true) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                if (mid == 1 || !isBadVersion(mid - 1)) {
                    ans = mid;
                    break;
                } else {
                    r = mid - 1;
                }
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};