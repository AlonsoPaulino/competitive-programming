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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int lc = 0, uc = 0, nn = 0;
        for (auto x: s) {
            if (x >= '0' && x <= '9') ++nn;
            else if (x >= 'a' && x <= 'z') ++lc;
            else ++uc;
        }
        int cnt = 0;
        if (lc == 0) ++cnt; 
        if (uc == 0) ++cnt;
        if (nn == 0) ++cnt;

        if (cnt == 2) {
            int k = 0;
            if (lc == 0) s[k++] = 'a';
            if (uc == 0) s[k++] = 'A';
            if (nn == 0) s[k++] = '4';
        } else if (cnt == 1) {
            for (int k = 0; k < sz(s); ++k) {
                char x = s[k];
                if (x >= '0' && x <= '9' && nn > 1) {
                    if (uc == 0) s[k] = 'A'; else s[k] = 'a';
                    break;
                } else if (x >= 'a' && x <= 'z' && lc > 1) {
                    if (uc == 0) s[k] = 'A'; else s[k] = '4';
                    break;
                } else if (x >= 'A' && x <= 'Z' && uc > 1) {
                    if (lc == 0) s[k] = 'a'; else s[k] = '4';
                    break;
                }
            }
        }
        cout << s << endl;
    }
}
