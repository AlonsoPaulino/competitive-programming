class Solution {
    typedef pair<pair<int, int>, int> node;
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int i, int j, int n) {
        return !(i < 0 || i >= n || j < 0 || j >= n);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, -1));
        stack<node> ss;
        ss.push({{0, 0}, 1});
        int dir = 0;
        while (!ss.empty()) {
            auto u = ss.top(); ss.pop();
            auto pos = u.first;
            auto val = u.second;
            int i = pos.first, j = pos.second;
            v[i][j] = val;
            int ii = i + dx[dir], jj = j + dy[dir], k = 0;
            while (k < 4 && (!isValid(ii, jj, n) || v[ii][jj] != -1)) {
                ++k;
                dir += k;
                dir %= 4;
                ii = i + dx[dir], jj = j + dy[dir];
            }
            if (k < 4) {
                int ii = i + dx[dir], jj = j + dy[dir];
                if (v[ii][jj] == -1) {
                    ss.push({{ii, jj}, val + 1});
                }
            }
        }
        return v;
    }
};
