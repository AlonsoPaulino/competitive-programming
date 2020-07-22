#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
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

int r, c;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> r >> c;
    char v[r][c];
    int a = 0, b = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < r; ++i) {
        bool flag = false;
        for (int j = 0; j < c; ++j) {
            if (v[i][j] == 'S') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            a += c;
            for (int j = 0; j < c; ++j) v[i][j] = 'X';
        }
    }
    for (int j = 0; j < c; ++j) {
        bool flag = false;
        for (int i = 0; i < r; ++i) {
            if (v[i][j] == 'S') {
                flag = true; break;
            }
        }
        if (!flag) {
            for (int i = 0; i < r; ++i) if (v[i][j] == '.') ++b;
        }
    }

    cout << a + b << endl;
}
