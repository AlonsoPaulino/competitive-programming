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
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        vector<int> v(4); int k = -1, w = -1;
        for (int i = 0; i < 4; ++i) cin >> v[i];
        for (int i = 0; i < 4; ++i) {
            if (k == -1 || v[i] > v[k]) k = i;
        }
        for (int i = 0; i < 4; ++i) {
            if (k != i && (w == -1 || v[i] > v[w])) w = i;
        }
        bool ans = (k < 2 && w > 1) || (k > 1 && w < 2);
        cout << (ans ? "YES" : "NO") << endl;
    }
}
