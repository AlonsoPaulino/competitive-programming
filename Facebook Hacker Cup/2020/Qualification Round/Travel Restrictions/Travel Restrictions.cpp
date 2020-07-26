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

const ll INF = (1LL << 60);

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    freopen("travel_restrictions_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n;
        string in, out; cin >> in >> out;
        vector<vll> fw(n + 5, vll(n + 5, INF));
        for (int i = 0; i < n; ++i) {
            fw[i][i] = 1LL;
            if (out[i] == 'Y') {
                if (i > 0 && in[i - 1] == 'Y') fw[i][i - 1] = 1LL;
                if (i < n - 1 && in[i + 1] == 'Y') fw[i][i + 1] = 1LL;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (fw[i][k] + fw[k][j] < fw[i][j]) fw[i][j] = min(INF, fw[i][k] + fw[k][j]);
                }
            }
        }

        cout << "Case #" << tc << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fw[i][j] < INF) cout << "Y";
                else cout << "N";
            }
            cout << "\n";
        }
    }
}