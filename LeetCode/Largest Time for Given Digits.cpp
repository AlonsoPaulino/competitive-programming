class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int hour = -1, minutes = -1;
        do {
            int hh = A[0] * 10 + A[1];
            int mm = A[2] * 10 + A[3];
            if (hh < 24 && mm < 60) {
                hour = hh, minutes = mm;
            }
        } while(next_permutation(A.begin(), A.end()));
        if (hour == -1) return "";
        string h = to_string(hour), m = to_string(minutes);
        int nh = (int) h.size(), nm = (int) m.size();
        if (nh == 1) h = "0" + h; else if (nh == 0) h = "00";
        if (nm == 1) m = "0" + m; else if (nm == 0) m = "00";
        return h + ":" + m;
    }
};