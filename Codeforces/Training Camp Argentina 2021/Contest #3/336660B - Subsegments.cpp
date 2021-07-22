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
    int n, k; cin >> n >> k;
    vi v(n + 5);
    for (int i = 0; i < n; ++i) cin >> v[i];
    map<int, int> cnt;
    map<int, bool> m;
    for (int i = 0; i < n; ++i) {
        if (i >= k) {
            int cntk = --cnt[v[i - k]];
            if (cntk <= 0) {
                m.erase(v[i - k]);
            } else if (cntk == 1) {
                m[v[i - k]] = true;
            }
            if (cntk <= 0) {
                cnt.erase(v[i - k]);
            }
        }
        auto it = cnt.find(v[i]);
        if (it == cnt.end() || it->second == 0) {
            m[v[i]] = true;
            cnt[v[i]]++;
        } else {
            it->second++;
            m.erase(v[i]);
        }
        if (i + 1 >= k) {
            if (m.empty()) {
                cout << "Nothing\n";       
            } else {
                cout << prev(m.end())->first << endl;
            }
        }
    }
}
