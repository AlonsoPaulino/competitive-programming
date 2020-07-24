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

const int MAX = 1000200;

ll n;
bitset<MAX + 1> bs;

void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    for (ll i = 2; i <= MAX; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= MAX; j += i) bs[j] = 0;
        }
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    sieve();
    vi dp(MAX, 0);
    for (int i = 1; i < MAX; ++i) {
        dp[i] = dp[i - 1];
        if (bs[i]) dp[i]++;
    }
    int a, b, k, ans = -1;
    cin >> a >> b >> k;
    int last = a;
    for (int l = 1; l <= b - a + 1; ++l) {
        bool flag = true;
        for (int x = last; x <= b - l + 1; ++x) {
            int cnt = dp[x + l - 1] - dp[x - 1];
            if (cnt < k) {
                flag = false;
                break;
            }
            last = x;
        }
        if (flag) {
            ans = l;
            break;
        }
    }
    cout << ans << endl;
}
