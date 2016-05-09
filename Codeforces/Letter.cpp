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
#define MAX 50
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, l, r, t, d;
char v[MAX + 5][MAX + 5];

int main() {
    while (cin >> n >> m) {
        l = t = MAX + 19, r = d = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
                if (v[i][j] == '*') {
                    l = min(l, j);
                    r = max(r, j);
                    t = min(t, i);
                    d = max(d, i);
                }
            }
        }
        for (int i = t; i <= d; ++i) {
            for (int j = l; j <= r; ++j) {
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
}