#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ull t, n;

ull gcd(ull a, ull b) {
    if (b == (ull) 0) return a;
    return gcd(b, a % b);
}

ull lcm(ull a, ull b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (lcm(n + 1, 4 * n) / (n + 1)) + 1 << "\n";
    }
}