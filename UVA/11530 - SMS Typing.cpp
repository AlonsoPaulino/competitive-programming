#include <bits/stdc++.h>
#define sz(x) x.size();

typedef long long ll;
using namespace std;

int t, l;
ll ans;
string s;

int v[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
	cin >> t;
	getline(cin, s);
	for (int i = 1; i <= t; ++i) {
		ans = 0;
		getline(cin, s);
		l = sz(s);
		for (int j = 0; j < l; ++j) {
			if (s[j] != ' ') {
				int ascii = s[j] - 'a';
				ans += v[ascii];
			} else {
				++ans;
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}
