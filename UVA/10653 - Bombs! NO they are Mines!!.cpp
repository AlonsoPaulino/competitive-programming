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
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int N = 1000;
const int DELTA = 4;

bool v[N][N];
int r, c, n, b, row, column, rx, ry, x, y;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool isValidPosition(int i, int j) {
  return (i >= 0 && i < r && j >= 0 && j < c && v[i][j]);
}

int bfs(int rootX, int rootY, int destinyX, int destinyY) {
  bool visited[r][c];
  mset2dd(visited, 0, r, c);
  queue< pair< pii, int> > q;
  q.push(mp(mp(rootX, rootY), 0));
  visited[rootX][rootY] = 1;
  while (!q.empty()) {
    pair< pii, int> front = q.front(); q.pop();
    for (int i = 0; i < DELTA; ++i) {
      int nextX = front.fi.fi + dx[i];
      int nextY = front.fi.se + dy[i];
      if (nextX == destinyX && nextY == destinyY) {
        return front.se + 1;
      }
      if (isValidPosition(nextX, nextY) && !visited[nextX][nextY]) {
        q.push(mp(mp(nextX, nextY), front.se + 1));
        visited[nextX][nextY] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> r >> c) {
    if (!r && !c) break;

    mset2d(v, 1, N);
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> row >> b;
      for (int j = 0; j < b; ++j) {
        cin >> column;
        v[row][column] = 0;
      }
    }

    cin >> rx >> ry >> x >> y;
    int ans = bfs(rx, ry, x, y);
    cout << ans << "\n";
  }

  return 0;
}
