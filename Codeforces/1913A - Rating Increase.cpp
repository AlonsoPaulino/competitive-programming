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
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        int a = s[0] - '0', b = 0;
        int i = 1;
        while (i < sz(s) && s[i] == '0') {
            a *= 10;
            a += (s[i] - '0');
            ++i;
        }
        while (i < sz(s)) {
            b *= 10;
            b += (s[i] - '0');
            ++i;
        }
        if (b > a) {
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
