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
#define mset(v, x) memset(v, x, sizeof(v))
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; int ans = INF; cin >> s;
    unordered_map<char, int> um;
    um['R'] = um['G'] = um['B'] = INF;
    int n = sz(s);
    for (int i = 0; i < n; ++i) {
        um[s[i]] = min(um[s[i]], i == 0 || i + 1 == n ? 1 : 2);
    }
    bool found = false;
    for (int i = 0; i + 3 <= n; ++i) {
        set<char> st;
        for (int j = i; j < i + 3; ++j) st.insert(s[j]);
        if (sz(st) == 3) {
            found = true;
            int aux;
            if (i == 0 && n == 3) aux = 0;
            else aux = i == 0 || i + 3 == n ? 1 : 2;
            ans = min(ans, aux);
        }
    }
    if (!found) {
        for (int i = 0; i + 2 <= n; ++i) {
            set<char> st;
            for (int j = i; j < i + 2; ++j) st.insert(s[j]);
            if (sz(st) == 2) {
                int aux = i == 0 || i + 2 == n ? 1 : 2;
                if (st.find('R') == st.end()) {
                    aux += um['R'];
                } else if (st.find('G') == st.end()) {
                    aux += um['G'];
                } else if (st.find('B') == st.end()) {
                    aux += um['B'];
                }
                if (aux < INF) {
                    found = true;
                    ans = min(ans, aux);
                }
            }
        }
    }
    if (!found) {
        ans = um['R'] + um['G'] + um['B'];
    }
    cout << ans << endl;
}
