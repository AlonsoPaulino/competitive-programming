#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) x.size()
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define all(v) v.begin, v.end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string s;
int ans;

int main() {
	while (cin >> s) {
		ans = 0;
		ans += (26 * (sz(s) + 1));
		ans -= 	sz(s);
		cout << ans << endl;
	}
}