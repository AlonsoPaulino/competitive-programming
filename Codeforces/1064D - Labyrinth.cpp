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
#define N 2005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

// Note, changing the way I read the table (read string per row instead of each characters) ended up
// reducing the time for this solution (before this change was 1232 ms, now is 405 ms)

// Using priority queue because we want to prioritize those nodes that has a lesser cumulative L & R.

bool v[N][N];
bool visit[N][N];

int n, m, r, c, x, y, total;

struct node {
    int i, j, left, right;

    bool friend operator <(const node a, const node b) {
        return a.left + a.right > b.left + b.right;
    }
};

int d[4][4] = {
    -1, 0, 0, 0,
    1, 0, 0, 0,
    0,-1, 1, 0,
    0, 1, 0, 1
};

bool valid(int i, int j, int l, int r) {
    return v[i][j] && !visit[i][j] && i >= 0 && i < n && j >= 0 && j < m && l <= x && r <= y;
}
    
void bfs(int i, int j) {
    node front;
    front.i = i;
    front.j = j;
    front.left = 0;
    front.right = 0;

    priority_queue<node> q;
    q.push(front);

    visit[i][j] = true;

    while (!q.empty()) {
        front = q.top(); q.pop();

        ++total;

        for (int k = 0; k < 4; ++k) {
            int nexti = front.i + d[k][0];
            int nextj = front.j + d[k][1];
            int nextl = front.left + d[k][2];
            int nextr = front.right + d[k][3];

            if (valid(nexti, nextj, nextl, nextr)) {
                visit[nexti][nextj] = true;
                node next;
                next.i = nexti, next.j = nextj, next.left = nextl, next.right = nextr;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> r >> c >> x >> y;

    --r, --c;

    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i][j] = (s[j] == '.');
        }
    }

    total = 0;

    bfs(r, c);

    cout << total << "\n";
}