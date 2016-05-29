#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pss pair<string, string>
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

int n;
pss p;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector< pss > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].second == "rat") {
            cout << v[i].first << "\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].second == "woman" || v[i].second == "child") {
            cout << v[i].first << "\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].second == "man") {
            cout << v[i].first << "\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].second == "captain") {
            cout << v[i].first << "\n";
        }
    }
}