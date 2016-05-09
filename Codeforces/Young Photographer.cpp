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

bool possible = 1;
int a, b, li, ls, n, x;

int main() {
    cin >> n >> x;
    ls = 1000 + 10, li = -1;
    while (n--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (b < li || a > ls) possible = 0;
        if (a >= li && a <= ls) {
            li = a;
        } else {
            li = max(li, a);
        }
        if (b >= li && b <= ls) {
            ls = b;
        } else {
            ls = min(ls, b);
        }
    }
    if (!possible) {
        cout << "-1\n";
    } else {
        if (x >= li && x <= ls) {
            cout << "0\n";
        } else if (x < li) {
            cout << li - x << "\n";
        } else if (x > ls) {
            cout << x - ls << "\n";
        }
    }
}