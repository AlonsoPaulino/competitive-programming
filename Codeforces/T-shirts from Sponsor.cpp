#include <bits/stdc++.h>
using namespace std;

pair<int,string> v[5];
map<string, int> m;

int k, n;
string t;

void init() {
	m["S"] = 0;
	m["M"] = 1;
	m["L"] = 2;
	m["XL"] = 3;
	m["XXL"] = 4;
	v[0] = make_pair(0, "S");
	v[1] = make_pair(0, "M");
	v[2] = make_pair(0, "L");
	v[3] = make_pair(0, "XL");
	v[4] = make_pair(0, "XXL");
}

void testarray() {
	for (int i = 0; i < 5; ++i) {
		cout << "i -> " << v[i].first << endl;
	}
}

int main() {
	init();
	for (int i = 0; i < 5; ++i) cin >> v[i].first;
	cin >> k;
	while (k--) {
		cin >> t;
		int p = m[t];
		if (v[p].first > 0) {
			cout << v[p].second << endl;
			--v[p].first;
		} else {
			int aux = 1;
			bool ans = false;
			while ((p - aux >= 0 || p + aux < 5) && !ans) {
				if (p + aux < 5 && v[p + aux].first > 0) {
					cout << v[p + aux].second << endl;
					--v[p + aux].first;
					ans = true;
				}
				if (p - aux >= 0 && v[p - aux].first > 0 && !ans) {
					cout << v[p - aux].second << endl;
					--v[p - aux].first;
					ans = true;
				}
				++aux;
			}
		}
	}
}