class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int nA = A.size(), nB = B.size();
        while (i < nA && j < nB) {
            vector<int> aux(2);
            aux[0] = max(A[i][0], B[j][0]);
            aux[1] = min(A[i][1], B[j][1]);
            if (aux[1] >= aux[0]) {
                ans.push_back(aux);
            }
            if (A[i][1] <= B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
};