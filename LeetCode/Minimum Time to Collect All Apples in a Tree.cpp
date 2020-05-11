class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector< vector<int> > ady(n);
        for (auto& e: edges) {
            ady[e[0]].push_back(e[1]);
        }
        return dfs(0, ady, hasApple);
    }
    
    int dfs(int node, vector<vector<int>>& ady, vector<bool>& hasApple) {
        vector<int> childs = ady[node];
        if (childs.size() == 0) {
            return hasApple[node] ? 2 : 0;
        }
        int childsCost = 0;
        for (auto& child: childs) childsCost += dfs(child, ady, hasApple);
        int myCost = hasApple[node] ? 2 : 0;
        int totalCost = max(myCost, childsCost);
        if (childsCost > 0 && node != 0) totalCost += 2;
        return totalCost;
    }
};