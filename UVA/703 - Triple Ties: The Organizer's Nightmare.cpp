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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 100
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int v[MAX + 5][MAX + 5];

bool draw(int x, int y) {
    return v[x][y] == 0 && v[y][x] == 0;
}

bool cycle(int x, int y, int z) {
    return (v[x][y] && v[y][z] && v[z][x]) || (v[y][x] && v[z][y] && v[x][z]);
}

pair< bool, vi > undecidable(int x, int y, int z) {
    pair< bool, vi > result = mp(0, vi(0));
    if (draw(x, y) && draw(y, z) && draw(x, z)) {
        result.fi = 1;
        result.se.pb(x);
        result.se.pb(y);
        result.se.pb(z);
    } else if (cycle(x, y, z)) {
        result.fi = 1;
        if (v[x][y] && v[y][z]) {
            result.se.pb(x);
            result.se.pb(y);
            result.se.pb(z);
        } else {
            result.se.pb(z);
            result.se.pb(y);
            result.se.pb(x);
        }
    }
    return result;
}

bool cmp(vi v1, vi v2) {
    if (v1[0] < v2[0]) return 1;
    if (v2[0] < v1[0]) return 0;
    if (v1[1] < v2[1]) return 1;
    if (v2[1] < v1[1]) return 0;
    return v1[2] < v2[2];
}

int n;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                cin >> v[i][j];
            }
        }
        vector< vi > ans;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                for (int k = j + 1; k < n + 1; ++k) {
                    pair< bool, vi > aux = undecidable(i, j, k);
                    if (aux.fi) {
                        ans.pb(aux.se);
                    }
                }
            }
        }
        sort(all(ans), cmp);
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
        }
    }
    return 0;
}