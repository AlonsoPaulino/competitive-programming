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

int t;
string e;

char neg(char x) {
    if (x == '1') return '0';
    if (x == '0') return '1';
    if (x == 'x') return 'X';
    return 'x';
}

char evaluate(char a, char op, char b) {
    if (op == '&') {
        if (a == '0' || b == '0') return '0';
        if (a == '1') return b;
        if (b == '1') return a;
        if (a != b) return '0';
        return a;
    } else if (op == '|') {
        if (a == '1' || b == '1') return '1';
        if (a == '0') return b;
        if (b == '0') return a;
        if (a == b) return a;
        return '1';
    } else {
        if (a == '1' && b == '1') return '0';
        if (a == '0' && b == '0') return '0';
        if (a == '1' && b == '0') return '1';
        if (a == '0' && b == '1') return '1';
        if (a == '1') return neg(b);
        if (b == '1') return neg(a);
        if (a == '0') return b;
        if (b == '0') return a;
        if (a != b) return '1';
        return '0';
    }
}

void print_stack(stack<char> c) {
    while (!c.empty()) {
        cout<<c.top();
        c.pop();
    }

    cout << "\n";
}

int main() {
    freopen("mr_x.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> e;

        int l = sz(e);

        char result;

        if (l > 1) {
            stack<char> s;

            for (int j = 0; j < l; ++j) {
                if (e[j] != '(' && e[j] != ')') {
                    s.push(e[j]);
                } else if (e[j] == ')') {
                    char b = s.top(); s.pop();
                    char op = s.top(); s.pop();
                    char a = s.top(); s.pop();

                    char r = evaluate(a, op, b);

                    s.push(r);
                }
            }

            result = s.top();
        } else {
            result = e[0];
        }

        if (result != '1' && result != '0') {
            cout << "Case #" << i << ": 1\n";
        } else {
            cout << "Case #" << i << ": 0\n";
        }
    }
}