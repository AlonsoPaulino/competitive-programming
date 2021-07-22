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
vi v(N);

int find(int x) {
  return (x == v[x]) ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
  v[find(x)] = find(y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<int> st;
    set<int> ans;
    for (int i = 0; i < N; ++i) v[i] = i;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        st.insert(s[0] - 'a');
        for (int j = 1; j < sz(s); ++j) {
            st.insert(s[j] - 'a');
            join(s[j - 1] - 'a', s[j] - 'a');
        }
    }
    for (auto it: st) {
        ans.insert(find(it));
    }
    cout << sz(ans) << endl;
}
