#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool islucky(string s) {
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != '4' && s[i] != '7') return 0;
    }
    return 1;
}

int cont(string p, string s) {
    int cnt = 0;
    for (int i = 0; i + sz(p) - 1 < sz(s); ++i) {
        string aux = s.substr(i, sz(p));
        if (p == aux) ++cnt;
    }
    return cnt;
}

string solve(string s) {
    int aux = -1;
    string ans;
    for (int i = 0; i < sz(s); ++i) {
        for (int j = 1; j < sz(s) - i + 1; ++j) {
            string saux = s.substr(i, j);
            if (islucky(saux)) {
                int caux = cont(saux, s);
                if (caux > aux) {
                    aux = caux;
                    ans = saux;
                } else if (caux == aux) {
                    if (saux < ans) {
                        aux = caux;
                        ans = saux;
                    }
                }
            }
        }
    }
    if (aux < 0) return "-1";
    return ans;
}

string s;

int main() {
    cin >> s;
    cout << solve(s) << "\n";
}
