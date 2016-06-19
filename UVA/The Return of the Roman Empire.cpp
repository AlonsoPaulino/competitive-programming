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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

map<int, string> m;
map<char, int> base;

void initmap() {
    base['I'] = 1, base['V'] = 5, base['X'] = 10, base['L'] = 50, base['C'] = 100, base['D'] = 500, base['M'] = 1000;
    m[1] = "I", m[5] = "V", m[10] = "X", m[50] = "L", m[100] = "C", m[500] = "D", m[1000] = "M";
    for (int i = 1, r = 1; i < 4000; i += r) {
        if (i % (10 * r) == 0) r *= 10;
        if (sz(m[i]) == 0) {
            if (i <= 3 * r) {
                for (int j = r; j <= i; j += r) {
                    m[i] += m[r];
                }
            } else if (i == 4 * r) {
                m[i] = m[r] + m[5 * r];
            } else if (i <= 8 * r) {
                m[i] = m[5 * r];
                for (int j = 6 * r; j <= i; j += r) {
                    m[i] += m[r];
                }
            } else if (i == 9 * r) {
                m[i] = m[r] + m[10 * r];
            }
        }
    }
    for (int i = 1; i < 4000; ++i) {
        if (sz(m[i]) == 0) {
            int n = i, p = 1, d;
            string aux = "";
            while (n  > 0) {
                d = (n % 10) * p;
                p *= 10;
                aux = m[d] + aux;
                n /= 10;
            }
            m[i] = aux;
        }
    }
}

string s;
int ans;
bool valid;

int main() {
    ios::sync_with_stdio(false);
    initmap();
    while (getline(cin, s)) {
        ans = 0, valid = 1;
        if (sz(s) > 0) {
            for (int i = 0; i < sz(s); ++i) {
                if (i > 0 && base[s[i]] > base[s[i - 1]]) {
                    ans = ans - 2 * base[s[i - 1]] + base[s[i]];
                } else {
                    ans += base[s[i]];
                }
            }
        }
        if (m[ans] != s) valid = 0;
        if (valid) {
            cout << ans << "\n";
        } else{
            cout << "This is not a valid number\n";
        }
    }
}