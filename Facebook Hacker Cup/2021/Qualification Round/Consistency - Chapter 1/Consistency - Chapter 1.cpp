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

bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("consistency_chapter_1_input.txt", "r", stdin);
    freopen("consistency_chapter_1_output.txt", "w", stdout);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        string s; cin >> s;
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            char c = (char) ('A' + i);
            int cnt = 0;
            bool a = is_vowel(c);
            for (int j = 0; j < sz(s); ++j) {
                if (c != s[j]) {
                    bool b = is_vowel(s[j]);
                    a != b ? cnt += 1 : cnt += 2;
                }
            }
            ans = (ans == -1) ? cnt : min(ans, cnt);
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
