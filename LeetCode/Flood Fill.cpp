class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int di[4] = { 1, -1, 0, 0 };
        int dj[4] = { 0, 0, 1, -1 };
        int cc = image[sr][sc];
        
        if (cc == newColor) return image;
        
        stack< pair<int, int> > s;
        s.push({sr, sc});
        while (!s.empty()) {
            pair<int, int> p = s.top(); s.pop();
            image[p.first][p.second] = newColor;
            for (int i = 0; i < 4; ++i) {
                int ni = p.first + di[i];
                int nj = p.second+ dj[i];
                if (ni >= 0 && ni < image.size() && 
                    nj >= 0 && nj < image[ni].size() && 
                    image[ni][nj] == cc) {
                    s.push({ni, nj});
                }
            }
        }
        
        return image;
    }
};