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

int x, y;

bool ciel() {
    int acum = 0;
    while (acum < 200 && x > 0) {
        acum += 100, x--;
    }
    while (acum < 220 && y > 0) {
        acum += 10, y--;
    }
    return acum == 220;
}

bool hanako() {
    if (y >= 22) {
        y -= 22;
        return true;
    }
    if (y >= 12 && x >= 1) {
        y -= 12, x -= 1;
        return true;
    }
    if (y >= 2 && x >= 2) {
        y -= 2, x -= 2;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x >> y;
    string winner = "";
    while (true) {
        if (!ciel()) {
            winner = "Hanako";
            break;
        }
        if (!hanako()) {
            winner = "Ciel";
            break;
        }
    }
    cout << winner << endl;
}
