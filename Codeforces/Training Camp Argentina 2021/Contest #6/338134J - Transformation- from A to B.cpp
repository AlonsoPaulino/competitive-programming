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

stack<int> op;
long a, b;

bool solve(int x) {
    if (x < a) return false;
    if (x == a) return true;
    if (x % 2 == 0) {
        op.push(x / 2);
        return solve(x / 2);
    } else if (x % 10 == 1) {
        op.push((x - 1) / 10);
        return solve((x - 1) / 10);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    bool ans = solve(b);
    if (ans) {
        cout << "YES\n";
        cout << sz(op) + 1 << endl;
        while (!op.empty()) {
            cout << op.top() << " ";
            op.pop();
        }
        cout << b << endl;
    } else {
        cout << "NO" << endl;
    }
}
