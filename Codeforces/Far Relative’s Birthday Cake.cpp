#include <bits/stdc++.h>
#define vi vector<int>
#define sz(x) x.size()
#define debug(x) cout<<#x<<":"<<x<<endl
#define test() cout<<"hola papa"
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n;

int main() {
	while (cin >> n) {
		char v[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
			}
		}
		int ans = 0, ansx = 0, ansy = 0;
		for (int i = 0; i < n; ++i) {
			ansy = 0;
			for (int j = 0; j < n; ++j) {
				if (v[i][j] == 'C') {
					++ansy;
				}
			}
			ans += (ansy * (ansy-1))/2;
		}
		for (int i = 0; i < n; ++i) {
			ansx = 0;
			for (int j = 0; j < n; ++j) {
				if (v[j][i] == 'C') {
					++ansx;
				}
			}
			ans += (ansx * (ansx- 1))/2;
		}
		cout << ans << endl;
	}
}