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
#define MAX 100000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n;
vi v(MAX + 5);

int main() {
    while (cin >> n) {
        vb aux(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            cin >> v[i];
            if (v[i] < n + 1) {
                aux[v[i]] = 1;
            }
        }
        queue<int> q;
        for (int i = 1; i < n + 1; ++i) {
            if (!aux[i]) q.push(i);
        }
        for (int i = 1; i < n + 1; ++i) {
            if (v[i] < n + 1 && aux[v[i]]) {
                aux[v[i]] = 0;
                cout << v[i];
            } else {
                int x = q.front();
                q.pop();
                cout << x;
            }
            if (i < n) cout << " ";
        }
        cout << "\n";
    }
}