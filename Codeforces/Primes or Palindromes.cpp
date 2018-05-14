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
#define MAX 10000001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

double a, p, q;

vi v(MAX + 5);
vi rub(MAX + 5);
bitset<MAX + 5> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAX; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX; j += i) {
                bs[j] = 0;
            }
        }
    }
}

bool isPalindrome(int x) {
    string s = "";
    while (x > 0) {
        s += ((x % 10) + '0');
        x /= 10;
    }
    for (int i = 0; i < sz(s) / 2; ++i) {
        if (s[i] != s[sz(s) - i - 1]) return 0;
    }
    return 1;
}


void initsets() {
    sieve();
    v[0] = 0, rub[0] = 0;
    for (int i = 1; i < MAX; ++i) {
        v[i] = v[i - 1];
        rub[i] = rub[i - 1];
        if (bs[i]) ++v[i];
        if (isPalindrome(i)) ++rub[i];
    }
}

int main() {
    initsets();
    while (cin >> p >> q) {
        a = p / q;
        for (int i = MAX - 1; i >= 0; --i) {
            if (a * rub[i] - v[i] >= 0.0) {
                cout << i << endl;
                break;
            }
        }
    }
}

