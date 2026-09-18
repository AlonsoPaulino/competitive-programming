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

ll gcdll(ll x, ll y) {
    if (x == 0LL) return y;
    if (y == 0LL) return x;
    if (x == y) return x;

    if (x > y) return gcd(x - y, y);

    return gcd(y - x, x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll a, b, k; cin >> a >> b >> k;
        if (k >= a && k >= b || (a == b)) {
            cout << 1 << endl; 
        } else {
            ll x = gcdll(a, b);
            if (k >= a / x && k >= b / x) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
}
