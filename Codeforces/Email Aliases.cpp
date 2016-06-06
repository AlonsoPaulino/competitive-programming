#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 2 * 10000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string clean(string s) {
    string result = "", domain = "";
    int ls = sz(s) - 1;
    for (ls; ls >= 0; --ls) {
        if (s[ls] == '@') break;
        domain += tolower(s[ls]);
    }
    reverse(all(domain));
    bool add = 1, ignore = (domain == "bmail.com");
    for (int i = 0; i < ls; ++i) {
        if (s[i] == '+' && ignore) add = 0;
        if (add) {
            if (s[i] == '.') {
                if (!ignore) result += s[i];
            } else {
                result += tolower(s[i]);
            }
        }
    }
    return result + "@" + domain;
}

map<int, string> aux;
map<string, vs> m;

int main() {
    ios::sync_with_stdio(false);
    int n, groups = 0, index = 0; 
    string s, sc;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sc = clean(s);
        if (sz(m[sc]) == 0) {
            aux[index++] = sc;
            ++groups;
        }
        m[sc].pb(s);
    }
    map<int, string>::iterator it = aux.begin();
    cout << groups << "\n";
    for (it; it != aux.end(); ++it) {
        string email = it->se;
        int lse = sz(m[email]);
        cout << lse << " ";
        for (int i = 0; i < lse; ++i) {
            cout << (m[email])[i];
            if (i + 1 < lse) cout << " ";
        }
        cout << "\n";
    }
}
