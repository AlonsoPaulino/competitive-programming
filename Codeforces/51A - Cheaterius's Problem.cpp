#include <bits/stdc++.h>
using namespace std;

struct amulet {
	
	int a, b, c, d;

	bool similar(amulet x) {
		if (a == x.a && b == x.b && c == x.c && d == x.d) return true;
		if (a == x.c && b == x.a && c == x.d && d == x.b) return true;
		if (a == x.d && b == x.c && c == x.b && d == x.a) return true;
		if (a == x.b && b == x.d && c == x.a && d == x.c) return true;
		return false;
	}
};

int n;
string s;

int main() {
	cin >> n;
	vector<amulet> v(n);
	vector<amulet> ans;
	for (int i = 0; i < n; ++i) {
		amulet a;
		cin >> s;
		a.a = s[0] - '0', a.b = s[1] - '0';
		cin >> s;
		a.c = s[0] - '0', a.d = s[1] - '0';
		if (i != n-1) cin >> s;
		v[i] = a;
	}
	ans.push_back(v[0]);
	for (int i = 1; i < n; ++i) {
		amulet a = v[i];
		bool flag = false;
		for (int j = 0; j < ans.size() && !flag; ++j) {
			if (a.similar(ans[j])) flag = true;
		}
		if (!flag) ans.push_back(a);
	}
	cout << ans.size() << endl;
}