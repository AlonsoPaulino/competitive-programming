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

const int MAX = 100;

bool points[MAX + 5][MAX + 5][MAX + 5][MAX + 5];
bool v[MAX + 5][MAX + 5];
int w, h, n;
pii begin, end;
vi ans;

int dtop[] = {0, 0, 0, 1};
int dbottom[] = {1, 0, 1, 1};
int dright[] = {0, 1, 1, 1};
int dleft[] = {0, 0, 1, 0};

int dfs(int x, int y) {
    v[x][y] = false;
    int result = 1;
    pii p1, p2;

    p1.fi = x + dtop[0], p1.se = y + dtop[1];
    p2.fi = x + dtop[2], p2.se = y + dtop[3];

    if (!points[p1.fi][p1.se][p2.fi][p2.se] && v[x - 1][y]) {
        result += dfs(x - 1, y);
    }

    p1.fi = x + dbottom[0], p1.se = y + dbottom[1];
    p2.fi = x + dbottom[2], p2.se = y + dbottom[3];

    if (!points[p1.fi][p1.se][p2.fi][p2.se] && v[x + 1][y]) {
        result += dfs(x + 1, y);
    }

    p1.fi = x + dright[0], p1.se = y + dright[1];
    p2.fi = x + dright[2], p2.se = y + dright[3];

    if (!points[p1.fi][p1.se][p2.fi][p2.se] && v[x][y + 1]) {
        result += dfs(x, y + 1);
    }

    p1.fi = x + dleft[0], p1.se = y + dleft[1];
    p2.fi = x + dleft[2], p2.se = y + dleft[3];

    if (!points[p1.fi][p1.se][p2.fi][p2.se]&& v[x][y - 1]) {
        result += dfs(x, y - 1);
    }

    return result;
}

int main() {
    cin >> w >> h >> n;
    for (int i = 0; i < n; ++i) {
        cin >> begin.fi >> begin.se;
        cin >> end.fi >> end.se;
        if (begin.fi == end.fi) {
            for (int k = begin.se; k < end.se; ++k) {
                points[begin.fi + 1][k + 1][begin.fi + 1][k + 2] = 1;
            } 
        } else {
            for (int k = begin.fi; k < end.fi; ++k) {
                points[k + 1][begin.se + 1][k + 2][begin.se + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            v[i][j] = 1;
        }
    }
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            if (v[i][j]) {
                int result = dfs(i, j);
                ans.pb(result);
            }
        }
    }
    sort(all(ans));
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << (i + 1 < sz(ans) ? " " : "\n");
    }
}