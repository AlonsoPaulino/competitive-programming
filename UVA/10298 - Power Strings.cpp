#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

string s;
vector<int> z(MAX);
int ls, ans, aux;

void z_function() {
	z[0] = 0;
	int r = 0, l = 0, k;
	for (int i = 1; i < ls; ++i) {
		if (i > r) {
			l = r = i;
			while (r < ls && (s[r] == s[r - l])) r++;
			z[i] = r - l;
			r--;
		} else {
			k = i - l;
			if (z[k] < (r - i + 1)) {
				z[i] = z[k];
			} else {
				l = i;
				while (r < ls && (s[r] == s[r - l])) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

int main() {
	while (cin >> s) {
		ls = s.size();

		if (ls == 1 && s[0] == '.') {
			return 0;	
		}

		z_function();
		ans = 1;
		int i = ans;
		bool flag  = false;

		while (!flag) {
			if (i >= ls) {	
				flag = true;
			} else {
				if (z[i] >= ans) {
					i += ans;
				} else {
					ans++;
					while (ls % ans != 0) ans++;
					if (ans == ls) {
						flag = true;
					} else {
						i = ans;
					}
				}
			}
		}

		cout << ls/ans << endl;
	}
}