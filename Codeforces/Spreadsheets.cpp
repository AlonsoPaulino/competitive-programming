#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1000000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n;
string s;

string toChar(string sx) {
    int x;
    istringstream iss(sx);
    iss >> x;
    string result = "";
    while (x > 26) {
        int r = x % 26;
        int q = x / 26;
        if (r > 0) {
            x = q;
            result += ('A' + r - 1);
        } else {
            x = q - 1;
            r = 26;
            result += ('A' + r - 1);
        }
    }
    result += ('A' + x - 1);
    reverse(all(result));
    return result;
}

int toInt(string x) {
    int result = 0, aux = 1;
    for (int i = sz(x) - 1; i >= 0; --i) {
        result += ((x[i] - 'A' + 1) * aux);
        aux *= 26;
    }
    return result;
}

bool ischar(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isnumber(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> s;
        vector<string> v1, v2;
        int i = 0; string aux = "";
        while (i < sz(s) && ischar(s[i])) aux += s[i], ++i; if (sz(aux) > 0) v1.pb(aux); aux = "";
        while (i < sz(s) && isnumber(s[i])) aux += s[i], ++i; if (sz(aux) > 0) v2.pb(aux); aux = "";
        while (i < sz(s) && ischar(s[i])) aux += s[i], ++i; if (sz(aux) > 0) v1.pb(aux); aux = "";
        while (i < sz(s) && isnumber(s[i])) aux += s[i], ++i; if (sz(aux) > 0) v2.pb(aux); aux = "";
        if (sz(v1) == 1) {
            cout << "R" << v2[0] << "C" << toInt(v1[0]) << endl;
        } else {
            cout << toChar(v2[1]) << v2[0] << endl;
        }
    }
}
