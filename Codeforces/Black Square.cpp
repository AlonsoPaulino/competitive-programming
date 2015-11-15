#include <bits/stdc++.h>
using namespace std;

string s;
int a1, a2, a3, a4, ans;

int main() {
	while (cin >> a1 >> a2 >> a3 >> a4) {
		ans = 0;
		cin >> s;
		int l = s.size();
		for (int i = 0; i < l; ++i) {
			int val = s[i] - '0';
			if (val == 1) ans += a1;
			else if (val == 2) ans += a2;
			else if (val == 3) ans += a3;
			else ans += a4;
		}
		cout << ans << endl;
	}
}
