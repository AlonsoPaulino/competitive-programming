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

int n, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    int cnt = 0, i = 0;
    while (i + 1 < n) {
        if (cnt < k) {
            if (s[i] == '4' && s[i + 1] == '7') {
                if ((i + 1) & 1) {
                    s[i] = s[i + 1] = '4';
                    ++cnt;
                } else {
                    if (i > 0 && s[i - 1] == '4') {
                        if ((k - cnt) & 1) {
                            s[i] = s[i + 1] = '7';
                        }
                        cnt = k;
                    } else {
                        s[i] = s[i + 1] = '7';
                        ++cnt;
                    }
                }
            }
        } else break;
        ++i;
    }
    cout << s << "\n";
}


