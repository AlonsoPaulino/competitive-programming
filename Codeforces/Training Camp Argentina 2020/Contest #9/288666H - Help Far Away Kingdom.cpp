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

bool is_less(string s) {
    return (s[0] - '0') < 5;
}

string sum(string a, string b) {
    if (sz(a) < sz(b)) swap(a, b);
    int j = sz(a) - 1;
    for(int i = sz(b) - 1; i >= 0; i--, j--) a[j] += (b[i] - '0');
    for(int i = sz(a) - 1; i > 0; i--){
        if (a[i] > '9') {
            int d = a[i]-'0';
            a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
            a[i] = (d % 10) + '0';
        }
    }
    if (a[0] > '9') {
        string k; k += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        a = k + a;
    }
    return a;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    string num, dec;
    int i = 0;
    while (i < sz(s) && s[i] != '.') num += s[i], ++i;
    ++i; while (i < sz(s)) dec += s[i], ++i;
    int n = sz(num), nd = sz(dec);
    if (num[n - 1] == '9') {
        cout << "GOTO Vasilisa.\n";
    } else {
        if (is_less(dec)) {
            cout << num << endl;
        } else {
            cout << sum(num, "1") << endl;
        }
    }
}
