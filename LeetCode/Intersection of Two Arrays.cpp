class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        vector<int> ans;
        for (auto x: nums1) st.insert(x);
        for (auto x: nums2) {
            auto it = st.find(x);
            if (it != st.end()) {
                ans.push_back(*it);
                st.erase(it);
            }
        }
        return ans;
    }
};
