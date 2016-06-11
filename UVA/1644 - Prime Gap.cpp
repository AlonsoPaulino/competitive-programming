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
#define MAX 1299710
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bitset<MAX + 1> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAX + 1; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX + 1; j += i) {
                bs[j] = 0;
            }
        }
    }
}

int k, ans;

int main() {
    ios::sync_with_stdio(false);
    sieve();
    while (cin >> k) {
        if (k == 0) return 0;
        if (bs[k]) {
            ans = 0;
        } else {
            int l = k, r = k;
            while (!bs[l]) --l;
            while (!bs[r]) ++r;
            ans = r - l;
        }
        cout << ans << "\n";
    }
}