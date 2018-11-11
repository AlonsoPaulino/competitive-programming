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


int v[105][30];
vector<string> dict;

int main() {
    ios::sync_with_stdio(false);
    mset2dd(v, 0, 105, 30);
    
    string s;
    int k = 0;

    while (cin >> s) {
        if (s == "XXXXXX") break;

        dict.pb(s);

        for (int i = 0; i < sz(s); ++i) {
            v[k][s[i] - 'a']++;
        }

        ++k;
    }

    vector< vs > ans;

    while (cin >> s) {
        if (s == "XXXXXX") break;

        vi d(30, 0);
        vs da;

        for (int i = 0; i < sz(s); ++i) {
            d[s[i] - 'a']++;
        }

        for (int i = 0; i < sz(dict); ++i) {
            bool match = true;

            for (int j = 0; match && j < 30; ++j) {
                if (d[j] != v[i][j]) match = false;
            }

            if (match) {
                da.pb(dict[i]);
            }
        }

        if (sz(da) > 0) {
            sort(all(da));
        } else {
            da.pb("NOT A VALID WORD");
        }

        ans.pb(da);
    }

    for (int i = 0; i < sz(ans); ++i) {
        for (int j = 0; j < sz(ans[i]); ++j) {
            cout << ans[i][j] << "\n";
        }
        cout << "******\n";
    }
}
