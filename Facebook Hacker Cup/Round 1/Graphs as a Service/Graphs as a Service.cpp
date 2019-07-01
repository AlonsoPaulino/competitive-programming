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
#define MAX 50
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = (1LL << 60);

int t, n, m, x, y;
ll dxy;

int main() {
    freopen("graphs_as_a_service.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for (int c = 1; c <= t; ++c)  {
        cin >> n >> m;

        int ans[m][3];
        
        vector< vector< ll > > ady(n + 1, vector< ll >(n + 1, INF));

        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> dxy;
            ans[i][0] = x, ans[i][1] = y, ans[i][2] = dxy;
            ady[x][y] = dxy;
            ady[y][x] = dxy;
        }

        ll dist[n + 1][n + 1];
    
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = ady[i][j];
            }
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        bool valid = true;

        for (int i = 0; i < m && valid; ++i) {
            if (dist[ans[i][0]][ans[i][1]] != ans[i][2]) valid = false; 
        }

        if (valid) {
            cout << "Case #" << c << ": " << m << "\n";
            for (int i = 0; i < m; ++i) {
                cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
            }
        } else {
            cout << "Case #" << c << ": " << "Impossible" << "\n";
        }
    }
}