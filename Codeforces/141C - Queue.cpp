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

const int MAX = 3000;

int n, a;
bool possible = 1;
string name;
vector< pair<string, int> > v;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.se < p2.se;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name >> a;
        v.pb(mp(name, a));
    }
    sort(all(v), cmp);
    vector<int> h(n);
    for (int i = 0; i < n && possible; ++i) {
        if (v[i].se > i) possible = 0;
    }
    if (!possible) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; ++i) {
            h.insert(h.begin() + i - v[i].se, i);
        }
        for (int i = 0; i < n; ++i) {
            v[h[i]].se = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << v[i].fi << " " << v[i].se << "\n";
        }
    }
    return 0;
}