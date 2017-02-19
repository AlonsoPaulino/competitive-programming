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
#define mod(x, m) ((x % m) + m) % m
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

bitset<1000001> bs;
int n;
ll x;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sz(bs); ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= sz(bs); j += i) {
                bs[j] = 0;
            }
        }
    }
}

int main() {
    sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ll r = sqrt(x);
        cout << (r * r == x && bs[r] ? "YES\n" : "NO\n");
    }
}