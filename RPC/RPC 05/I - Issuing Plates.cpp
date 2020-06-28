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

const int N = 28;

struct node {
    bool word;
    node *v[N];    
};

node *trie;

node *new_node() {
    node *x = (node *)malloc(sizeof(node));
    if (x) {
        x->word = false;
        for (int i = 0; i < N; ++i) x->v[i] = NULL;
    }
    return x;
}

char leetspeak(char c) {
    switch (c) {
    case '0': return 'O';
    case '1': return 'L';
    case '2': return 'Z';
    case '3': return 'E';
    case '5': return 'S';
    case '6': return 'B';
    case '7': return 'T';
    case '8': return 'B';
    default:
        return c;
    }
}

void insert(string s) {
    node *x = trie;
    for (int i = 0; i < sz(s); ++i) {
        int k = s[i] - 'A';
        if (!x->v[k]) {
            x->v[k] = new_node();
        }
        x = x->v[k];
    }
    x->word = true;
}

bool search(string s, int k) {
    node *x = trie;
    for (int i = k; i < sz(s); ++i) {
        char c = s[i];
        if (c == '4' || c == '9') return false;
        x = x->v[leetspeak(c) - 'A'];
        if (!x) return false;
        if (x->word) return true;
    }
    return x != 0 && x->word;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    trie = new_node();

    int n, m;
    cin >> n >> m;
    string s;
    while (n--) {
        cin >> s;
        insert(s);
    }
    while (m--) {
        cin >> s;
        bool valid = true;
        for (int i = 0; i < sz(s); ++i) {
            valid &= !(search(s, i));
            if (!valid) break;
        }
        cout << (!valid ? "INVALID" : "VALID") << endl;
    }
}
