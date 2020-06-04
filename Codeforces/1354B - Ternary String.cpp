#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int t;
string s;

void two_pointers_solution() {
    cin >> t;
    while (t--) {
        cin >> s;
        set<char> st;
        int ans = 0;
        int i = 0, j = 0;
        while (i + 1 < sz(s) && s[i + 1] == s[i]) ++i;
        j = i + 1;
        st.insert(s[i]);
        while (j < sz(s)) {
            char c = s[j];
            if (s[i] == c) {
                i = j - 1;
            }
            st.insert(c);
            if (sz(st) == 3) {
                ans = ans == 0 ? j - i + 1 : min(ans, j - i + 1);
                st.clear();
                ++i;
                while (i + 1 < sz(s) && s[i + 1] == s[i]) ++i;
                j = i + 1;
                st.insert(s[i]);
            } else {
                ++j;
            }
        }
        cout << ans << endl;
    }
}

void binary_search_solution() {
    cin >> t;
    while (t--) {
        cin >> s;
        int l = 3, r = sz(s);
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            map<char, int> m;
            for (int i = 0; i < mid; ++i) {
                m[s[i]]++;
            }
            bool found = false;
            if (m['1'] && m['2'] && m['3']) found = true;
            for (int i = mid; i < sz(s) && !found; ++i) {
                m[s[i]]++;
                m[s[i - mid]]--;
                if (m['1'] && m['2'] && m['3']) found = true;
            }
            if (found) {
                debug2(l, r);
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    two_pointers_solution();
}
