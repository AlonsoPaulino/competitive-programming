class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int y = target - x;
            if (m.find(y) != m.end() && i != m[y]) {
                ans[0] = i;
                ans[1] = m[y];
                break;
            }
        }
        return ans;
    }
};

/* Another solution written at 12/27/2020 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        vector<int> ans;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int x = nums[i], y = target - x;
            if (x == y && (int) m[x].size() > 1) {
                ans.push_back(m[x][0]);
                ans.push_back(m[x][1]);
                break;
            } else if (x != y && m.find(y) != m.end()) {
                ans.push_back(m[x][0]);
                ans.push_back(m[y][0]);
                break;
            }
        }
        return ans;
    }
};

// Another solution written on 07/02/2021
class Solution {
public:
    int bs(vector<pair<int, int>> &v, int start, int end, int k) {
        int lo = start, hi = end;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid].first < k) {
                lo = mid + 1;
            } else if (v[mid].first > k) {
                hi = mid - 1;
            } else return v[mid].second;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int) nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) v.push_back({ nums[i], i });
        sort(v.begin(), v.end());
        for (int i = 0; i + 1 < n; ++i) {
            int x = v[i].first, y = target - x;
            int j = bs(v, i + 1, n - 1, y);
            if (j != -1) {
                vector<int> ans(2, 0);
                ans[0] = v[i].second, ans[1] = j;
                return ans;
            }
        }
        return vector<int>();
    }
};
