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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 2 * 100001
#define vll vector<ll>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int l, r, n, q;

void modify(vll &bit, int x, int add) {
    while (x < sz(bit)) {
        bit[x] += add;
        x += (x & -x);
    }
}

ll read(vll &bit, int x) {
    ll sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= (x & -x);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    vll bit(n + 1, 0);
    vll v(n), aux(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    while (q--) {
        cin >> l >> r;
        modify(bit, l, 1);
        modify(bit, r + 1, -1);
    }
    for (int i = 1; i < n + 1; ++i) {
        aux[i - 1] = read(bit, i);
    }
    sort(all(aux));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (v[i] * aux[i]);
    }
    cout << ans << "\n";
}