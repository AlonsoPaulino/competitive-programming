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
#define MAX 11
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, a, b;
string ans;
bool ans1, ans2;
vector< pair< string, pii > > v(MAX);

string tostring(int num) {
    string sn = "";
    while (num != 0) {
        sn += ((num % 10) + '0');
        num /= 10;
    }
    if (sz(sn) < 4) {
        while (sz(sn) != 4) {
            sn += '0';
        }
    }
    reverse(all(sn));
    return sn;
}

bool validText(string text) {
    map<char, int> m;
    for (int i = 0; i < sz(text); ++i) {
        if (m[text[i]]) return 0;
        m[text[i]] = 1;
    }
    return 1;
}

bool check(string p, string t, int x, int y) {
    int eq = 0, diff = 0;
    for (int i = 0; i < sz(p); ++i) {
        for (int j = 0; j < sz(t); ++j) {
            if (p[i] == t[j]) {
                (i == j) ? ++eq : ++diff;
                break;
            }
        }
    }
    return eq == x && diff == y;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ans = "", ans1 = ans2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].fi >> v[i].se.fi >> v[i].se.se;
    }
    string num = "";
    for (int i = 0; i < 10000 && !(ans1 && ans2); ++i) {
        num = tostring(i);
        if (validText(num)) {
            for (int j = 0; j < n; ++j) {
                if (!check(v[j].fi, num, v[j].se.fi, v[j].se.se)) {
                    break;
                } else {
                    if (j + 1 == n) {
                        ans = num;
                        if (ans1 && !ans2) ans2 = 1;
                        if (!ans1) ans1 = 1;
                    }
                }
            }
        }
    }
    if (ans1 && ans2) {
        cout << "Need more data\n";
    } else {
        if (ans != "") {
            cout << ans << "\n";
        } else {
            cout << "Incorrect data\n";
        }
    } 
}