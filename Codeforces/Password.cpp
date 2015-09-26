#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans;
bool flag = false;

void z_function(vector<int> &z) {
	int l, r, k;
	l = r = 0;
	for (int i = 1; i < n; ++i) {
		if (i > r) {
			l = r = i;
			while (r < n && (s[r - l] == s[r])) r++;
			z[i] = r - l;
			r--;
		} else {
			k = i - l;
			if (z[k] < r -i + 1) {
				z[i] = z[k]; 
			} else {
				l = i;
				while (r < n && (s[r - l] == s[r])) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

int main() {
	while (cin >> s) {
		flag = false, n = s.size();
		vector<int> z(n);
		z_function(z);

		int max = 0;
		for (int i = 1; i < (n - 1) && !flag; ++i) {
			int j = i + 1;
			if (z[i] > max) max = z[i];
			if (max >= z[j]) {
				if (z[j] + j == n) {
					ans = j;
					flag = true;
				}
			}
		}

		if (flag) {
			for (int i = ans; i < n; ++i) {
				cout << s[i];
			}
		} else {
			cout << "Just a legend";
		}

		endl(cout);
	}
}
