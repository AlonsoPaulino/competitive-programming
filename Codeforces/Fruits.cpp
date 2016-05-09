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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, maxi, mini;
string s;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        vi v1(n);
        vi v2;
        map<string, int> aux;
        map<string, int>::iterator it;
        maxi = mini = 0;
        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < m; ++i) {
            cin >> s;
            aux[s]++;
        }
        for (it = aux.begin(); it != aux.end(); ++it) {
            v2.pb(it->second);
        }
        sort(all(v1)), sort(all(v2));
        int k = n - 1;
        for (int i = sz(v2) - 1; i >= 0; --i) {
            maxi += (v2[i] * v1[k--]);
        }
        k = 0;
        for (int i = sz(v2) - 1; i >= 0; --i) {
            mini += (v2[i] * v1[k++]);
        }
        cout << mini << " " << maxi << endl;
    }
}