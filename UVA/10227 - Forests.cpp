#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define ssz(x) (int) strlen(x)
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
#define MAX 100
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int aux, t, p, xi, xj;
char c[10];
vi v(MAX + 5);

void initset() {
    for (int i = 0; i <= p; ++i) {
        v[i] = i;
    }
}

int find(int x) {
    return x == v[x] ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
    v[find(x)] = find(y);
}

bool setAreEquals(set<int> s1, set<int> s2) {
    if (sz(s1) == sz(s2)) {
        set<int>::iterator it = s1.begin();
        while (it != s1.end()) {
            if (!s2.count(*it)) return 0;
            ++it;
        }
        return 1;
    }
    return 0;
}

void checkForOppinions(vector< set<int> > vx) {
    for (int i = 1; i <= t; ++i) {
        set<int> s1 = vx[i];
        for (int j = i + 1; j <= t; ++j) {
            set<int> s2 = vx[j];
            if (setAreEquals(s1, s2)) {
                join(i, j);
            }
        }
    }
}

int main() {
    scanf("%d", &aux);
    while (aux--) {
        scanf("%d %d", &p, &t);
        vector< set<int> > vaux(t + 5);
        getchar(), initset();
        while (gets(c)) {
            if (ssz(c) == 0) break;
            sscanf(c, "%d %d", &xi, &xj);
            vaux[xi].insert(xj);
        }
        checkForOppinions(vaux);
        set<int> ans;
        for (int i = 1; i <= p; ++i) {
            ans.insert(find(i));
        }
        printf("%d\n", sz(ans));
        if (aux > 0) printf("\n");
    }
}
