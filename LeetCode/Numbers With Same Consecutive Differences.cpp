class Solution {
    vector<int> ans;
public:
    void dfs(int root, int n, int k) {
        stack<pair<int, int>> ss;
        ss.push({root, root});
        while (!ss.empty()) {
            auto x = ss.top(); ss.pop();
            int dd = (int) log10(x.first) + 1;
            if (dd == n) {
                ans.push_back(x.first);
                continue;
            }
            int a = x.second + k, b = x.second - k;
            if (a < 10) ss.push({ x.first * 10 + a, a });
            if (b >= 0 && b != a) ss.push({ x.first * 10 + b, b });
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) ans.push_back(0);
        for (int i = 1; i < 10; ++i) dfs(i, N, K);
        return ans;
    }
};