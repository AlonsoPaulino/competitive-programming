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

int n, x;

int main() {
    while (cin >> n) {
        vi v(n + 1, 0);
        set<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i + 1 < n; ++i) {
            x = abs(v[i] - v[i + 1]);
            if (x > 0 && x < n) {
                s.insert(x);
            }
        }
        cout << (sz(s) == (n - 1) ? "Jolly\n" : "Not jolly\n");
    }
}