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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll MAX = 1000000000000000000;

int n, t, s;
ll x;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    ll likes = 0LL;

    map<ll, int> m;
    map<ll, int>::iterator it;

    for (int i = 0; i < n; ++i) {
        cin >> t >> s;

        for (int j = 0; j < s; ++j) {
            cin >> x;

            if (t == 1) {
                if (m[x] != -1) {
                    ++m[x];
                }
            } else {
                m[x] = -1;
            }
        }

        if (t == 1) {
            ++likes;
        }
    }

    if (likes > 0) {
        ll ans = 0;

        for (it = m.begin(); it != m.end(); ++it) {
            if (it->se == likes) {
                ++ans;
            }
        }

       cout << ans << "\n";
    } else {
        ll diff = 0;

        for (it = m.begin(); it != m.end(); ++it) {
            if (it->se == -1) {
                ++diff;
            }
        }

        cout << MAX - diff << "\n";
    }
}