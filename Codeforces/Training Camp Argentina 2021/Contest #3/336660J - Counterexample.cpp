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
    ll a, b; cin >> a >> b;
    if (b - a < 2LL) cout << -1 << endl;
    else {
        if (b - a == 2LL) {
            if (a & 1) {
                cout << -1 << endl;
            } else {
                cout << a << " " << a + 1LL << " " << b << endl;
            }
        } else {
            if (a & 1) ++a;
            cout << a << " " << a + 1LL << " " << a + 2LL << endl;
        }
    }
}
