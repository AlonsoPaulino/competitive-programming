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
#define mod(x, m) ((x % m) + m) % m
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

bool valid = false;
int ans = -1;
string v[6];
string r[3];

bool search(string s, string pat) {
    char a = pat[0], b = pat[2];
    int i = 0;
    if (pat[1] == '<') {
        for (i; i < sz(s); ++i) {
            if (s[i] == a) {
                for (int j = i + 1; j < sz(s); ++j) {
                    if (s[j] == b) return true;
                }
                return 0;
            }
        }
    } else {
        for (i; i < sz(s); ++i) {
            if (s[i] == b) {
                for (int j = i + 1; j < sz(s); ++j) {
                    if (s[j] == a) return true;
                }
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    v[0] = "ABC", v[1] = "ACB";
    v[2] = "CBA", v[3] = "CAB";
    v[4] = "BAC", v[5] = "BCA";
    for (int i = 0; i < 3; ++i) cin >> r[i];
    for (int i = 0; i < 6 && !valid; ++i) {
        bool flag = true;
        for (int j = 0; j < 3; ++j) {
            if (!search(v[i], r[j])) {
                flag = false;
            }
        }
        if (flag) {
            valid = 1;
            ans = i;
        }
    }
    if (valid) {
        cout << v[ans] << "\n";
    } else {
        cout << "Impossible\n";
    }
}