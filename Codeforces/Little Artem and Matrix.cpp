#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 101
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, q, ti, ri, ci, xi;
int v[MAX][MAX];
map<int, int> hm;

void fixrow(int r) {
    int tmp = v[r][0];
    for (int i = 0; i < m - 1; ++i) {
        v[r][i] = v[r][i+1];
    }
    v[r][m-1] = tmp;
}

void fixcolumn(int c) {
    int tmp = v[0][c];
    for (int i = 0; i < n - 1; ++i) {
        v[i][c] = v[i+1][c];
    }
    v[n-1][c] = tmp;
}

void init() {
    int aux = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[i][j] = aux++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    init();
    while (q--) {
        cin >> ti;
        if (ti == 1) {
            cin >> ri;
            fixrow(ri-1);
        } else if (ti == 2) {
            cin >> ci;
            fixcolumn(ci-1);
        } else if (ti == 3) {
            cin >> ri >> ci >> xi;
            hm[v[ri-1][ci-1]] = xi;
        }
    }
    int aux = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ((!hm[aux]) ? 0 : hm[aux]);
            if (j < m-1) cout << " ";
            ++aux;
        }
        cout << "\n";
    }
    return 0;
}
