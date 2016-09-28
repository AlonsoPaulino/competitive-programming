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
#define MAX 10000000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, xi, li, ri;
bitset<MAX + 1> bs;
vector<int> seq(MAX + 1, 0);
vector<int> primes;
vector<ll> acum(MAX + 1, 0);

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= MAX; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
            }
            primes.pb((int) i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> xi;
        ++seq[xi];
    }
    for (int i = 0; i < sz(primes); ++i) {
        int p = primes[i];
        for (int j = p; j <= MAX; j += p) {
            acum[p] += seq[j];
        }
    }
    for (int i = 1; i <= MAX; ++i) {
        acum[i] += acum[i - 1];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> li >> ri;
        li = min(li, MAX);
        ri = min(ri, MAX);
        if (li > ri) swap(li, ri);
        if (li > 1) {
            cout << acum[ri] - acum[li - 1] << "\n";
        } else {
            cout << acum[ri] << "\n";
        }
    }
}