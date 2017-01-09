#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int MAX = 1000001;

int n, m;
bool visit[MAX + 5] = { false };

struct node {
    int value;
    int times;
};

node createNode(int v, int t) {
    node x;
    x.value = v, x.times = t;
    return x;
}

int bfs() {
    queue<node> q;
    q.push(createNode(n, 0));
    while (!q.empty()) {
        node current = q.front();
        visit[current.value] = 1;
        q.pop();
        if (current.value == m) {
            return current.times;
        }
        if (current.value > 0) {
            if (current.value < m && !visit[current.value * 2]) {
                q.push(createNode(current.value * 2, current.times + 1));
            }
            if (!visit[current.value - 1]) {
                q.push(createNode(current.value - 1, current.times + 1));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int ans = bfs();
    cout << ans << "\n";
}