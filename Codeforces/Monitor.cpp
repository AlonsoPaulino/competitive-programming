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
#define debug(x) cerr <<#x<<" : "<<x<<endl
#define debug2(x,y) cerr <<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr <<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ull a, b, x, y, k, ansx, ansy;

ull gcd(ull n1, ull n2) {
    if (n2 == 0) return n1;
    return gcd(n2, n1 % n2);
}

int main() {
    cin >> a >> b >> x >> y;
    ull tmp = gcd(x, y);
    x = x / tmp, y = y / tmp;
    k = sqrt((a * b) / (x * y));
    ansx = ansy = 0;
    if (k > 0) {
        ansx = k * x;
        ansy = k * y;
        while (ansx > a) {
            ansx = ansx - x;
            ansy = ansy - y;
        }
        while (ansy > b) {
            ansx = ansx - x;
            ansy = ansy - y;
        }
    }
    cout << ansx << " " << ansy << "\n";
    return 0;
}