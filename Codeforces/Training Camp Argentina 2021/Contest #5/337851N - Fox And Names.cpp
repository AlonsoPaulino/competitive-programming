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

const int N = 30;

stack<int> st;
vector<int> toposort;
vector<vector<int>> g(N, vector<int>());
vector<bool> visited(N, true);

int to_int(char c) {
    return (int) (c - 'a');
}

char to_char(int c) {
    return (char) ((int) 'a' + c); 
}

void dfs(int u) {
    visited[u] = 1;
    for (auto x: g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    st.push(u);
}

bool has_cycle() {
    vector<int> pos(N, -1);
    int idx = 0;
    while (!st.empty()) {
        pos[st.top()] = idx;
        toposort.push_back(st.top());
        idx++;
        st.pop();
    }
    for (int i = 0; i < N; ++i) {
        for (auto x: g[i]) {
            if (pos[i] > pos[x]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string a, b; cin >> a;
    bool flag = true;
    for (int i = 1; flag && i < n; ++i) {
        cin >> b;
        int sa = sz(a), sb = sz(b), j = 0;
        while (j < min(sa, sb) && a[j] == b[j]) ++j;
        if (j < min(sa, sb)) {
            int x = to_int(a[j]), y = to_int(b[j]);
            g[x].pb(y);
            visited[x] = visited[y] = false;
        } else if (sa > sb) {
            flag = false;
            break;
        }
        a = b;
    }
    if (!flag) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (has_cycle()) {
            cout << "Impossible\n";
        } else {
            string ans = "";
            for (auto x: toposort) {
                ans += to_char(x);
            }
            for (int i = 0; i < 26; ++i) {
                char x = to_char(i);
                bool found = false;
                for (auto c: ans) {
                    if (c == x) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ans += x;
                }
            }
            cout << ans << endl;
        }   
    }
}
