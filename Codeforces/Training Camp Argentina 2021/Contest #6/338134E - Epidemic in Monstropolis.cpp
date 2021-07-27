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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    int k; cin >> k;
    vi b(k); for (int i = 0; i < k; ++i) cin >> b[i];
    vector<pair<int, char>> v;
    int j = 0;
    bool ans = true;
    for (int i = 0; ans && i < k; ++i) {
        int target = b[i];
        int acum = 0, mx = -1;
        int lo = j, hi = -1;
        set<int> st;
        while (j < n && acum + a[j] <= b[i]) {
            acum += a[j];
            st.insert(a[j]);
            if (mx == -1) mx = j;
            else if (a[j] > a[mx]) mx = j;
            hi = j++;
        }
        if (acum == b[i] && (hi == lo || hi > lo && sz(st) > 1)) {
            if (mx > lo && a[mx] > a[mx - 1]) {
                for (int p = mx - 1; p >= lo; --p) {
                    v.push_back({p + 1 - lo + i + 1, 'L'});
                }
                for (int p = mx + 1; p <= hi; ++p) {
                    v.push_back({i + 1, 'R'});
                }
            } else {
                while (mx + 1 < hi && a[mx] == a[mx + 1]) ++mx;
                for (int p = mx + 1; p <= hi; ++p) {
                    v.push_back({i + mx - lo + 1, 'R'});
                }
                for (int p = mx - 1; p >= lo; --p) {
                    v.push_back({p + 1 - lo + i + 1, 'L'});
                }
            }
            continue;
        }
        ans = false;
    }
    if (!ans || j < n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto x: v) {
            cout << x.fi << " " << x.se << endl;
        }
    }
}
