#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 3
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vector<double> v(MAX);
bool ans = 0;
double d, e;

inline void check(double x, double y) {
    for (double i = 0; i <= 90; i += 0.001) {
        double radian = pi * i / 180.0;
        double a = x * sin(radian) + y * cos(radian);
        double b = y * sin(radian) + x * cos(radian);
        if ((a <= d && b <= e) || (a <= e && b <= d)) ans = 1;
    }
}

int main() {
    freopen("bricks.in", "r", stdin);
    freopen("bricks.out", "w", stdout);
    while (cin >> v[0] >> v[1] >> v[2] >> d >> e) {
        ans = 0;
        for (int i = 0; i < 3 && !ans; ++i) {
            for (int j = i + 1; j < 3 && !ans; ++j) {
                check(v[i], v[j]);
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}