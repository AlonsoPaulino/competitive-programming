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
    int n; cin >> n;
    bool flag = true;
    vi v(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n / 2; ++i) {
        if ((v[i] + v[n - i - 1]) % 2 == 0) {
            int x = (v[i] + v[n - i - 1]) / 2;
            int diff = v[i] - x;
            b[i] = diff, b[n - i - 1] = -diff;
            c[i] = c[n - i - 1] = x;
        } else {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (n & 1) {
            b[n / 2] = 0, c[n / 2] = v[n / 2];
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << (i + 1 < n ? " " : "\n");
        }
        for (int i = 0; i < n; ++i) {
            cout << c[i] << (i + 1 < n ? " " : "\n");
        }
    }
}
