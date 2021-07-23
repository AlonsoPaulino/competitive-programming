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

const ll MOD = 1000000007LL;
ll a, k;

unordered_map<ll, ll> mem;

ll mul(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll sum(ll x, ll y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll fastp(ll x, ll y) {
    if (y == 0LL) return 1LL;
    if (y == 1LL) return x;
    if (y & 1) {
        return mul(x, fastp(x, y - 1LL));
    }
    ll p = fastp(x, y / 2LL);
    return mul(p, p);
}

ll f(ll x, ll y) {
    if (x == y) {
        auto it = mem.find(x);
        if (it != mem.end()) {
            return it->second;
        } else {
            mem[x] = fastp(a, x);
            return mem[x];
        }
    }
    if (y & 1) {
        ll p = f(y, y);
        return sum(p, f(x, y - 1));
    } else {
        ll p = f(x, y / 2LL);
        return sum(p, mul(f(y / 2LL, y / 2LL), p));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> k;
    
    if (a == 1LL) {
        cout << sum(1LL, k) << endl;
    } else {
        ll ans = sum(1LL, f(1LL, k));
        cout << ans << endl;
    }
}
