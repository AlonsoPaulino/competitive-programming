class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n == 1) return true;
        vector<int> pivot = coordinates[0];
        int dx = pivot[0] - coordinates[1][0];
        int dy = (pivot[1] - coordinates[1][1]);
        double m = dy != 0 ? dx / dy : 0;
        for (int i = 1; i < n; ++i) {
            dx = pivot[0] - coordinates[i][0];
            dy = (pivot[1] - coordinates[i][1]);
            double x = dy != 0 ? dx / dy : 0;
            cout << x << endl;
            if (m != x) {
                return false;
            }
        }
        return true;
    }
};