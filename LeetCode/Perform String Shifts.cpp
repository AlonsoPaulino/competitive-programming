class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int l = 0, r = 0, n = (int) s.size();
        for (auto& x: shift) if (x[0] == 0) l+=x[1]; else r += x[1];
        int diff = abs(r - l) % n;
        if (r > l) {
            return s.substr(n - diff) + s.substr(0, n - diff);
        } else {
            return s.substr(diff) + s.substr(0, diff);
        }
        /* Even thought this is my original code, there is an improvement
        that can be discussed: Every right shift can be expressed as left shift
        since it is its complement in terms of string size. If the string size is 5,
        then, to achieve 3 right shifts, you would need 2 left shifts.
        With this idea in mind, we can just easily count either left shifts or right shifts
        and perform the computation getting rid of this if (r > l) :)
        */
    }
};