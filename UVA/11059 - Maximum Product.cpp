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
#define mod(x, m) ((x % m) + m) % m
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

ll n, c = 0;

int main() {
    while (cin >> n) {
        vector< ll > v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        vector< ll > maxi(n);
        vector< ll > mini(n);
     
        maxi[0] = mini[0] = v[0];
    
        ll result = v[0];
     
        for(int i = 1; i< n; i++){
            if(v[i]>0){
                maxi[i]= max(v[i], maxi[i-1]*v[i]);
                mini[i]= min(v[i], mini[i-1]*v[i]);
            }else{
                maxi[i]= max(v[i], mini[i-1]*v[i]);
                mini[i]= min(v[i], maxi[i-1]*v[i]);
            }
     
            result = max(result, maxi[i]);
        }
        result = max(result, 0LL);
        cout << "Case #" << ++c << ": The maximum product is " << result << ".\n\n";
    }
}