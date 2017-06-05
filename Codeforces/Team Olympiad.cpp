#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, x, total = 5001;

int main() {
    cin >> n;
    vi v[4], t(4);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[x].pb(i + 1);
        ++t[x];
    }
    total = min(t[1], min(t[2], t[3]));
    cout << total << "\n";
    for (int i = 0; i < total; ++i) {
        cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << "\n";
    }
}