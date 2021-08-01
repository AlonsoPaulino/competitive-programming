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

// Another solution written on 08/01/2021
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = (int) firstList.size();
        int m = (int) secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < n && j < m) {
            auto x = firstList[i], y = secondList[j];
            int a = max(x[0], y[0]), b = min(x[1], y[1]);
            if (b >= a) {
                vector<int> tmp;
                tmp.push_back(a), tmp.push_back(b);
                ans.push_back(tmp);
            }
            if (x[1] > y[1]) {
                ++j;
            } else if (x[1] < y[1]) {
                ++i;
            } else {
                ++i, ++j;
            }
        }
        return ans;
    }
};
