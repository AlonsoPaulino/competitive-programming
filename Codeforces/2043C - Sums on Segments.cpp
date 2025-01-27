#include <bits/stdc++.h>
#define PI acos(-1)
#define gcd(x,y) __gcd((x),(y))
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

pii min_max_subarray_sum(vi &v, int i, int j) {
    pii res = make_pair(0, 0); int tmp_min = 0, tmp_max = 0;
    for (int k = i; k <= j; ++k) {
        tmp_min += v[k], tmp_max += v[k];
        if (tmp_max < 0) tmp_max = 0; if (tmp_min > 0) tmp_min = 0;
        res = make_pair(min(res.fi, tmp_min), max(res.se, tmp_max));
    }
    return res;
}

pii min_max_continuous_sum(vi &v, int i, int j, bool reverse) {
    pii res = make_pair(0, 0); int tmp = 0;
    for (int k = reverse ? j : i; reverse ? k >= i : k <= j; reverse ? --k : ++k) {
        tmp += v[k];
        res = make_pair(min(res.fi, tmp), max(res.se, tmp));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi v(n); int xi = -1; 
        set<int> res;
        for (int i = 0; i < n; ++i) {
            cin >> v[i]; if (abs(v[i]) != 1) xi = i;
        }
        if (xi != -1) {
            pii l = min_max_subarray_sum(v, 0, xi - 1);
            pii r = min_max_subarray_sum(v, xi + 1, n - 1);

            res.insert(0); res.insert(v[xi]);
            for (int i = l.fi; i <= l.se; ++i) res.insert(i);
            for (int i = r.fi; i <= r.se; ++i) res.insert(i);
            
            pii ls = min_max_continuous_sum(v, 0, xi - 1, true);
            pii rs = min_max_continuous_sum(v, xi + 1, n - 1, false);

            for (int i = min(0, ls.fi + rs.fi); i <= max(0, ls.se + rs.se); ++i) res.insert(v[xi] + i);
        } else {
            pii m = min_max_subarray_sum(v, 0, n - 1);
            for (int i = m.fi; i <= m.se; ++i) res.insert(i);
        }

        int sz = (int) res.size(), cnt = 0;
        set<int>::iterator it = res.begin();
        cout << sz << endl;
        while (it != res.end()) {
            cout << *it; ++it, ++cnt; if (cnt != sz) cout << " ";;
        }
        cout << endl;
    }
}
