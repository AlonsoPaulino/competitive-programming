class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        set<int> st;
        for (auto it: arr) m[it]++;
        for (auto it: m) {
            st.insert(it.second);
        }
        return st.size() == m.size();
    }
};
