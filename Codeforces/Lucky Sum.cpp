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
#define MAX 4444444445
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vector<ll> v;

void init() {
    queue<ll> q;
    q.push(4), q.push(7);
    while (!q.empty()) {
        ll aux = q.front(); q.pop();
        v.pb(aux);
        ll n1 = aux * 10 + 4;
        ll n2 = aux * 10 + 7;
        if (n1 < MAX) q.push(n1);
        if (n2  < MAX) q.push(n2);
    }
}

ll next(ll x) {
    for (int i = 0; i < sz(v); ++i) {
        if (v[i] >= x) return v[i];
    }
    return v[sz(v) - 1];
}

ll l, r;
ll ans = 0;

int main() {
    init();
    cin >> l >> r;
    while (l <= r) {
        ll aux = next(l);
        ans += (aux * (min(aux, r) - l + 1));
        l = min(aux, r) + 1;
    }
    cout << ans << "\n";
}


