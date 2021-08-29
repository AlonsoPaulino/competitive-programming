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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("consistency_chapter_2_input.txt", "r", stdin);
    freopen("consistency_chapter_2_output.txt", "w", stdout);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        vector<vi> w(30, vector<int>(30, -1));
        vector<vi> ady(30, vector<int>());
        int k;
        string s, x; 
        cin >> s >> k;
        for (int i = 0; i < k; ++i) {
            cin >> x;
            ady[x[0] - 'A'].push_back(x[1] - 'A');
        }
        for (int i = 0; i < 26; ++i) {
            vector<bool> visit(30, false);
            queue<pii> q;
            q.push({i, 0}), visit[i] = true;
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                w[i][u.fi] = u.se;
                for (auto x: ady[u.fi]) {
                    if (!visit[x]) {
                        q.push({x, u.se + 1});
                        visit[x] = true;
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            int cnt = 0;
            for (int j = 0; j < sz(s); ++j) {
                if (w[s[j] - 'A'][i] == -1) {
                    cnt = -1;
                    break;
                }
                cnt += w[s[j] - 'A'][i];
            }
            if (cnt != -1) {
                ans = (ans == -1) ? cnt : min(ans, cnt);
            }
        }
        cout << "Case #" << tc << ": " << ans << endl; 
    }
}
