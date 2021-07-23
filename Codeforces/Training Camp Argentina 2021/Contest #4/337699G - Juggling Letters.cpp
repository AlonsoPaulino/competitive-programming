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
    int t, n; cin >> t;
    for (int k = 0; k < t; ++k) {
        cin >> n;
        unordered_map<int, int> m;
        for (int j = 0; j < n; ++j) {
            string s; cin >> s;
            for (auto x: s) m[x]++;
        }
        bool flag = true;
        for (auto it: m) {
            if (it.second % n != 0) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n"; else cout << "NO\n";
    }
}
