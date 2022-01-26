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

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("weak_typing_chapter_1_input.txt", "r", stdin);
    freopen("weak_typing_chapter_1_output.txt", "w", stdout);
    int t, n; cin >> t;
    string s;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> s;
        vector<vi> dp(n + 5, vi(2, 0));
        if (s[0] == 'F') dp[0][0] = dp[0][1] = 0;
        else if (s[0] == 'O') {
            dp[0][0] = 0, dp[0][1] = INF;
        } else {
            dp[0][0] = INF, dp[0][1] = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'F') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
            } else if (s[i] == 'O') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = INF;
            } else {
                dp[i][0] = INF;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
            }
        }
        cout << "Case #" << tc << ": " << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
}
