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

const int N = 40;

struct node {
    bool flag;
    node *v[N];
};

node *trie;

int charToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return 11 + (int) (c - 'a');
    }
    return (int) (c - '0');
}

node *createNode() {
    node *nd = (node *) malloc(sizeof(node));
    if (nd) {
        nd->flag = false;
        for (int i = 0; i < N; ++i) nd->v[i] = NULL;
    }
    return nd;
}

void insert(string word) {
    node *nd = trie;
    for (int i = 0; i < sz(word); i++) {
        int idx = charToIndex(word[i]);
        if (!nd->v[idx]) {
            nd->v[idx] = createNode();
        }
        nd = nd->v[idx];
    }
    nd->flag = true;
}

bool search(string word) {
    int n = word.size();
    node *nd = trie;
    for (int i = 0; i < n; ++i) {
        int idx = charToIndex(word[i]);
        nd = nd->v[idx];
        if (!nd) return false;
        else if (nd->flag) return true;
    }
    return nd != 0 && nd->flag;
}

int n, q;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    vs s, p;
    string aux;
    trie = createNode();
    while (n--) {
        cin >> aux;
        s.pb(aux);
    }
    while (q--) {
        cin >> aux;
        insert(aux);
    }
    vs ans;
    for (auto x: s) {
        bool found = search(x);
        if (!found) {
            ans.pb(x);
        }
    }
    sort(all(ans));
    cout << sz(ans) << endl;
    for (auto x : ans) {
        cout << x << endl;
    }
}
