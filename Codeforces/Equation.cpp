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
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

double a, b, c;
double r1, r2;

int main() {
    cin >> a >> b >> c;
    if (a != 0) {
        double dis = b * b - 4 * a * c;
        if (dis == 0) {
            printf("1\n%.5lf\n", (double) (-b / (2.0 * a)));
        } else if (dis > 0) {
            printf("2\n");
            r1 = (double) ((-b + (double) sqrt(dis)) / (2.0 * a));
            r2 = (double) ((-b - (double) sqrt(dis)) / (2.0 * a));
            if (r1 > r2) swap(r1, r2);
            printf("%.5lf\n%.5lf\n", r1, r2);
        } else {
            printf("0\n");
        }
    } else {
        if (b != 0) {
            printf("1\n%.5lf", (double) -c / b);
        } else {
            if (c == 0) printf("-1\n");
            else printf("0\n");
        }
    }
}