#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1000001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int a[MAX + 1];
int b[MAX + 1];
int t, n;

vi sum() {
	int aux, carry = 0;
	vi ans;
	for (int i = n - 1; i >= 0; --i) {
		aux = a[i] + b[i] + carry;
		carry = aux / 10;
		ans.pb(aux % 10);
	}
	return ans;
}

int main() {
	cin >> t;
	while (t-- ) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		vi result = sum();
		for (int i = sz(result) - 1; i >= 0; ++i) {
			cout << result[i];
		}
		cout << endl;
		if (t) cout << endl;
	}
}
