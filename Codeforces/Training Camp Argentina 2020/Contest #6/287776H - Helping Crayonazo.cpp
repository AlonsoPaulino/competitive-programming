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

const int MAX = 1000009;

ll n;
bitset<MAX + 1> bs;
vector<int> primes;

void segmented_sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= MAX; ++i){
        if(bs[i]){
            primes.push_back(i);
            for(long long j = i*i ; j <= MAX; j += i) bs[j] = 0;
		}
	}
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1LL) cout << "NO\n";
    else {
        segmented_sieve();
        vi v;
        int i = sz(primes) - 1;
        while (i >= 0) {
            int pw = 0;
            while (n % primes[i] == 0) n /= primes[i], pw++;
            if (pw > 0) v.pb(pw);
            --i;
        }
        if (n > 1LL) v.pb(1);
        int even = 0;
        for (int i = 0; i < sz(v); ++i) {
            if (v[i] % 2 == 0) even++;
        }
        if (even >= sz(v) - 1) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}
