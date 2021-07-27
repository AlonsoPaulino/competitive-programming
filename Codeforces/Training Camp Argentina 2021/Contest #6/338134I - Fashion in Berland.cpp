#include <bits/stdc++.h>
#define PI acos(-1)
#define gcd(x,y) __gcd((x),(y))
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n; int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 0) cnt++;
    }
    if (n == 1) {
        cout << (cnt == 0 ? "YES" : "NO") << endl;
    } else {
        if (cnt == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
