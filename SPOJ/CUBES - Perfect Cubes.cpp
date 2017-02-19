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

const int N = 100;

vi cubes(N + 5);
vector< set< vi > > ans(N + 5);

int main() {
    for (int i = 1; i <= N; ++i) {
        cubes[i] = i * i * i;
    }
    for (int i = 1; i <= N; ++i) {
        int a = cubes[i], b, c, d;
        for (int j = 2; j <= i; ++j) {
            b = cubes[j];
            for (int k = 2; k <= i; ++k) {
                c = cubes[k];
                for (int z = 2; z <= i; ++z) {
                    d = cubes[z];
                    if ((b + c + d) == a) {
                        vi aux;
                        aux.pb(j), aux.pb(k), aux.pb(z);
                        sort(all(aux));
                        ans[i].insert(aux);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        set< vi >::iterator it;
        for (it = ans[i].begin(); it != ans[i].end(); ++it) {
            cout << "Cube = " << i << ", Triple = (" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << ")\n";
        }
    }
}