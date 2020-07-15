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
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
 
    int r, s, p;
    cin >> r >> s >> p;
    double prob[r + 5][s + 5][p + 5];
    memset(prob, 0.0, sizeof(prob));
    prob[r][s][p] = 1.0;
    // conditional probability.
    // probability of having (i, j, k) alives given somebody was killed.
    for (int i = r; i >= 0; --i) {
        for (int j = s; j >= 0; --j) {
            for (int k = p; k >= 0; --k) {
                double sum = i * j + i * k + j * k;
                if (k > 0) prob[i][j][k] += prob[i + 1][j][k] * (double) ((i + 1) * k) / (double) (sum + j + k);
                if (i > 0) prob[i][j][k] += prob[i][j + 1][k] * (double) ((j + 1) * i) / (double) (sum + k + i);
                if (j > 0) prob[i][j][k] += prob[i][j][k + 1] * (double) ((k + 1) * j) / (double) (sum + i + j);
            }
        }
    }
    double ansr = 0.0, anss = 0.0, ansp = 0.0;
    for (int i = 1; i <= r; ++i) ansr += prob[i][0][0];
    for (int i = 1; i <= s; ++i) anss += prob[0][i][0];
    for (int i = 1; i <= p; ++i) ansp += prob[0][0][i];
    cout << setprecision(12) << ansr << " " << anss << " " << ansp << endl;
}