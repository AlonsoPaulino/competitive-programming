class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int k = 0;
        for (auto& a: A) {
            bool br = false;
            for (int j = k; j < B.size(); ++j) {
                vector<int> b = B[j];
                vector<int> aux(2);
                aux[0] = max(a[0], b[0]);
                aux[1] = min(a[1], b[1]);
                if (aux[1] >= aux[0]) {
                    ans.push_back(aux);
                    k = j;
                    br = true;
                } else {
                    if (br) break;
                }
            }
        }
        return ans;
    }
};