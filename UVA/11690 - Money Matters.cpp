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
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 10001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int t, n, m, xi, xj;
bool possible;
vi v(MAX);
vi c(MAX);

void initset() {
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
}

int find(int x) {
    return x == v[x] ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        c[ry] += c[rx];
        v[rx] = ry;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        possible = 1, initset();
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> xi >> xj;
            join(xi, xj);
        }
        for (int i = 0; i < n; ++i) {
            if (c[find(i)] != 0) {
                possible = 0;
                break;
            }
        }
        cout << ((possible) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
    return 0;
}