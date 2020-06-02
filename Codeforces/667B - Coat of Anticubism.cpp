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

int n, li;

int main() {
    cin >> n;
    vi v(n);
    int sum = 0, a = 0, b = 0, c;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    sort(all(v));
    for (int i = 0; i < n; ++i) {
        if (a + v[i] <= sum / 2) {
            a += v[i];
        } else {
            b = sum - a;
            break;
        }
    }
    cout << b - a + 1 << "\n";
}