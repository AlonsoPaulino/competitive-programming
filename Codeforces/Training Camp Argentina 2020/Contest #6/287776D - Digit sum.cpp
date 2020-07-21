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

string multiply(string s1, string s2) {
   int n = sz(s1);
   int m = sz(s2);
   string ans(n + m, '0');
   for(int i = n - 1; i >= 0; i--){
      for(int j = m - 1; j >= 0; j--){
         int p = (s1[i] - '0') * (s2[j] - '0') + (ans[i + j + 1] - '0');
         ans[i + j + 1] = p % 10 + '0';
         ans[i + j] += p / 10 ;
      }
   }
   for(int i = 0; i < n + m; i++){
      if(ans[i] !='0') return ans.substr(i);
   }
   return "0";
}

int sum(string s) {
    int x = 0;
    for (int i = 0; i < sz(s); ++i) {
        x += (s[i] - '0');
    }
    while (x >= 10) {
        int sum = 0;
        while (x > 0) {
            sum += (x % 10);
            x /= 10;
        }
        x = sum;
    }
    return x;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string a, acum = "1";
    vll v; v.pb(1);
    int b, k, p;
    cin >> a >> b;
    bool flag = true;
    while (flag) {
        acum = multiply(acum, a);
        int s = sum(acum);
        for (int i = 0; i < sz(v); ++i) {
            if (v[i] == s) {
                k = i;
                p = sz(v) - k;
                flag = false;
                break;
            }
        }
        if (flag) v.pb(s);
    }
    if (b < k) {
        cout << v[b];
    } else {
        cout << v[k + b % p];
    }
    cout << "\n";
}
