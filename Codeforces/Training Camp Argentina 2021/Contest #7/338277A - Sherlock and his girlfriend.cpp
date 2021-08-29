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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi ans(n, -1);
    for (ll i = 2L; i <= n + 1; ++i) {
        if (ans[i - 2] == -1) {
            ans[i - 2] = 1;
            for (ll j = i * i; j <= n + 1; j += i) {
                ans[j - 2] = 2;
            }
        }
    }
    cout << (n > 2 ? 2 : 1) << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i + 1 < n ? " " : "\n");
    }
}
