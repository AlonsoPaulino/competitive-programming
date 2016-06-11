#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, t, k;

ll f(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b == 1) return a % m;
    ll r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return r % m;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        double aux = k * log10(n);
        int right = f(n, k, 1000);
        int left = pow(10, aux - floor(aux) + 2.0);
        printf("%03d...%03d\n", left, right);
    }
    return 0;
}