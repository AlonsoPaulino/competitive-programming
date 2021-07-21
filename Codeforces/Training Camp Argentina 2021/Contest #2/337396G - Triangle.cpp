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

bool triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

bool degenerate(int a, int b, int c) {
    return a + b == c || b + c == a || a + c == b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vi v(4, -1); cin >> v[0] >> v[1] >> v[2] >> v[3];
    bool t = false, d = false;
    for (int i = 0; !t && i < 4; ++i) {
        for (int j = i + 1; !t && j < 4; ++j) {
            for (int k = j + 1; !t && k < 4; ++k) {
                if (triangle(v[i], v[j], v[k])) {
                    t = true;
                }
                if (degenerate(v[i], v[j], v[k])) d = true;
            }
        }
    }
    if (t) {
        cout << "TRIANGLE\n";
    } else if (d) {
        cout << "SEGMENT\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
