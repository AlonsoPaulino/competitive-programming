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
#define mset(v, x) memset(v, x, sizeof(v))
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    unordered_map<int, int> um;
    unordered_map<int, int>::iterator it;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        um[v[i]]++;
    }
    int nice_count = 0, extra_count = 0;
    for (it = um.begin(); it != um.end(); ++it) {
        if (it->second == 1) nice_count++;
        else if (it->second > 2) extra_count++;
    }

    if (nice_count % 2 == 0) {
        cout << "YES\n";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (um[v[i]] == 1) {
                if (cnt * 2 < nice_count) {
                    ++cnt;
                    cout << "A";
                } else cout << "B";
            } else cout << "A";
        }
        cout << endl;
    } else if(extra_count > 0) {
        cout << "YES\n";
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (um[v[i]] == 1) {
                if (cnt * 2 < nice_count) {
                    ++cnt;
                    cout << "A";
                } else cout << "B";
            } else if (um[v[i]] > 2 && flag) {
                cout << "B";
                flag = false;
            } else cout << "A";
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }
}
