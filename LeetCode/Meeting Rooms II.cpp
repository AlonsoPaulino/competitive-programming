class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = (int) intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for (int i = 1; i < n; ++i) {
            auto x = intervals[i];
            if (pq.top() <= x[0]) pq.pop();
            pq.push(x[1]);
        }
        return (int) pq.size();
    }
};

// Another solution written on 07/01/2021
const int N = 10e6 + 5;

class Solution {
public:
    int read(vector<int> &bit, int x) {
      int sum = 0;
      while (x > 0) {
        sum += bit[x];
        x -= (x & -x);
      }
      return sum;
    }
    
    void modify(vector<int> &bit, int x, int add) {
      while (x < N) {
        bit[x] += add;
        x += (x & -x);
      }
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> bit(N, 0);
        set<int> st;
        for (auto x: intervals) {
            x[0] += 1, x[1] += 1;
            modify(bit, x[0], 1);
            modify(bit, x[1], -1);
            st.insert(x[0]);
            st.insert(x[1]);
        }
        
        int ans = 0;
        for (auto it: st) {
            ans = max(ans, read(bit, it));
        }
        return ans;
    }
};
