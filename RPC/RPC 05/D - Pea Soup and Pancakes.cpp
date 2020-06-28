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

const string peasoup = "pea soup";
const string pancakes = "pancakes";

int n, k;
int bps[100], bpk[100];

void pre_process_ps() {
    int i = 0, j = -1; bps[0] = -1;
    while (i < sz(peasoup)) {
        while (j >= 0 && peasoup[i] != peasoup[j]) j = bps[j];
        ++i, ++j;
        bps[i] = j;
    }
}

void pre_process_pk() {
    int i = 0, j = -1; bpk[0] = -1;
    while (i < sz(pancakes)) {
        while (j >= 0 && pancakes[i] != pancakes[j]) j = bpk[j];
        ++i, ++j;
        bpk[i] = j;
    }
}

bool isPeasoup(string s) {
    int i = 0, j = 0;
    while (i < sz(s)) {
        while (j >= 0 && s[i] != peasoup[j]) j = bps[j];
        ++i, ++j;
        if (j == sz(peasoup)) return true;
    }
    return false;
}

bool isPancake(string s) {
    int i = 0, j = 0;
    while (i < sz(s)) {
        while (j >= 0 && s[i] != pancakes[j]) j = bpk[j];
        ++i, ++j;
        if (j == sz(pancakes)) return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    pre_process_pk();
    pre_process_ps();
    
    vs ans;

    cin >> n;
    while (n--) {
        cin >> k;
        cin.ignore(1, '\n'); 
        string name, menu;
        getline(cin, name);
        bool ps = false, pk = false;
        while (k--) {
            getline(cin, menu);
            if (!ps && isPeasoup(menu)) ps = true;
            if (!pk && isPancake(menu)) pk = true;
        }
        if (ps && pk) ans.pb(name);
    }

    if (sz(ans) < 1) cout << "Anywhere is fine I guess" << endl;
    else cout << ans[0] << endl;
}
