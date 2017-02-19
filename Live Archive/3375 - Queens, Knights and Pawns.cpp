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
#define mod(x, m) ((x % m) + m) % m
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

const int N = 1000;

int n, m, k, r, c, x, t = 1;

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector< vector< pii > > v(3);
        int board[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] = 1;
            }
        }
        for (int i = 0; i < 3; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> r >> c;
                v[i].pb(mp(r - 1, c - 1));
                board[r - 1][c - 1] = -1;
            }
        }
        for (int i = 0; i < sz(v[0]); ++i) {
            pii start = v[0][i];
            for (int j = start.fi - 1; j >= 0; --j) {
                if (board[j][start.se] == -1) break;
                if (board[j][start.se] == 1) board[j][start.se] = 0;
            }
            for (int j = start.fi + 1; j < n; ++j) {
                if (board[j][start.se] == -1) break;
                if (board[j][start.se] == 1) board[j][start.se] = 0;
            }
            for (int j = start.se - 1; j >= 0; --j) {
                if (board[start.fi][j] == -1) break;
                if (board[start.fi][j] == 1) board[start.fi][j] = 0;
            }
            for (int j = start.se + 1; j < m; ++j) {
                if (board[start.fi][j] == -1) break;
                if (board[start.fi][j] == 1) board[start.fi][j] = 0;
            }
            for (int j = 1; start.fi - j >= 0 && start.se + j < m; ++j) {
                if (board[start.fi - j][start.se + j] == -1) break;
                if (board[start.fi - j][start.se + j] == 1) board[start.fi - j][start.se + j] = 0;
            }
            for (int j = 1; start.fi + j < n && start.se + j < m; ++j) {
                if (board[start.fi + j][start.se + j] == -1) break;
                board[start.fi + j][start.se + j] = 0;
            }
            for (int j = 1; start.fi - j >= 0 && start.se - j >= 0; ++j) {
                if (board[start.fi - j][start.se - j] == -1) break;
                if (board[start.fi - j][start.se - j] == 1) board[start.fi - j][start.se - j] = 0;
            }
            for (int j = 1; start.fi + j < n && start.se - j >= 0; ++j) {
                if (board[start.fi + j][start.se - j] == -1) break;
                if (board[start.fi + j][start.se - j] == 1) board[start.fi + j][start.se - j] = 0;
            }
        }
        for (int i = 0; i < sz(v[1]); ++i) {
            pii start = v[1][i];
            if (start.fi + 2 < n && start.se - 1 >= 0) {
                board[start.fi + 2][start.se - 1] = 0;
            }
            if (start.fi + 2 < n && start.se + 1 < m) {
                board[start.fi + 2][start.se + 1] = 0;
            }
            if (start.fi - 2 >= 0 && start.se - 1 >= 0) {
                board[start.fi - 2][start.se - 1] = 0;
            }
            if (start.fi - 2 >= 0 && start.se + 1 < m) {
                board[start.fi - 2][start.se + 1] = 0;
            }
            if (start.fi + 1 < n && start.se - 2 >= 0) {
                board[start.fi + 1][start.se - 2] = 0;
            }
            if (start.fi + 1 < n && start.se + 2 < m) {
                board[start.fi + 1][start.se + 2] = 0;
            }
            if (start.fi - 1 >= 0 && start.se - 2 >= 0) {
                board[start.fi - 1][start.se - 2] = 0;
            }
            if (start.fi - 1 >= 0 && start.se + 2 < m) {
                board[start.fi - 1][start.se + 2] = 0;
            }
        }
        x = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 1) ++x;
            }
        }
        cout << "Board " << t++ << " has " << x << " safe squares.\n";
    }
    return 0;
}