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
#define debug(x) cerr <<#x<<" : "<<x<<endl
#define debug2(x,y) cerr <<#x<<" : "<<x<<" & "<<# y<<" : "<<y<<endl
#define test() cerr <<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, ans, cnt;
int hour, minute, aux, lasthour, lastminute;
string s, st1, st2;

int toint(char c) {
    return (int) c - '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    getline(cin, s), ans = cnt = 0;
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> st1, ss >> st2;
        if (ans > 0) {
            hour = toint(st1[1]) * 10 + toint(st1[2]);
            minute = toint(st1[4]) * 10 + toint(st1[5]);
            aux = (st2[0] == 'a') ? 0 : 1;
            if (aux) {
                hour = (hour % 12) + 12;    
            } else if (hour == 12) {
                hour = 0;
            }
            int current = hour * 60 + minute;
            int last = lasthour * 60 + lastminute;
            if (current == last) {
                ++cnt;
                if (cnt > 10) cnt = 1, ++ans;
            } else {
                cnt = 1;
                if (current < last) {
                    ++ans;   
                }    
            }
            lasthour = hour, lastminute = minute;
        } else {
            lasthour = toint(st1[1]) * 10 + toint(st1[2]);
            lastminute = toint(st1[4]) * 10 + toint(st1[5]);
            aux = (st2[0] == 'a') ? 0 : 1;
            if (aux) {
                lasthour = (lasthour % 12) + 12;
            } else if (lasthour == 12) {
                lasthour = 0;
            }
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}