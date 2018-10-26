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

// Note: I solved using dijkstra in past, using 0-1 BFS this time.

int n, m, r, c, x, y;

int d[4][4] = {
    -1, 0, 0, 0,
    1, 0, 0, 0,
    0, -1, 1, 0,
    0, 1, 0, 1 
};

struct node {
    int i, j, l, r;
};

node createNode(int i, int j, int l, int r) {
    node newNode;
    newNode.i = i, newNode.j = j, newNode.l = l, newNode.r = r;
    return newNode;
}

bool isValid(int i, int j, int l, int r) {
    return i >= 0 && i < n && j >= 0 && j < m && l <= x && r <= y;
}

int bfs(vector< vb > v) {
    int total = 0;

    vector< vi > di(n, vi(m, -1));

    node front = createNode(r, c, 0, 0);
    
    deque<node> q;
    q.push_front(front);

    di[r][c] = 0;

    while (!q.empty()) {
        front = q.front();
        q.pop_front();

        for (int i = 0; i < 4; ++i) {
            int ni = front.i + d[i][0];
            int nj = front.j + d[i][1];
            int nl = front.l + d[i][2];
            int nr = front.r + d[i][3];

            if (isValid(ni, nj, nl, nr) && v[ni][nj]) {
                if (di[ni][nj] == -1 || nl + nr < di[ni][nj]) {
                    di[ni][nj] = nl + nr;

                    node newNode = createNode(ni, nj, nl, nr);

                    i < 2 ? q.push_front(newNode) : q.push_back(newNode);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (di[i][j] != -1) {
                ++total;
            }
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> r >> c >> x >> y;
    --r, --c;

    string s;
    vector< vb > v(n, vb(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> s;

        for (int j = 0; j < m; ++j) {
            v[i][j] = (s[j] == '.');
        }
    }

    int answer = bfs(v);

    cout << answer << "\n";
}

