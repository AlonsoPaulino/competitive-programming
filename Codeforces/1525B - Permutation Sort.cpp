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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int ans = 2;
        int lo = 0, hi = 0;
        bool flag = true;
        for (int i = 1; i < n; ++i) {
            if (v[i] < v[lo]) lo = i;
            if (v[i] >= v[hi]) hi = i;
            flag &= v[i] >= v[i - 1];
        }
        if (flag) {
            ans = 0;
        } else if (lo == 0 || hi == n - 1) {
            ans = 1;
        } else if (hi == 0 && lo == n - 1) {
            ans = 3;
        }
        cout << ans << endl;
    }
}
