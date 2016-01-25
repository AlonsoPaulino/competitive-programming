#include <bits/stdc++.h>
#define vi vector<int>
#define MAX 100005
using namespace std;

string s;
int n, l , r, aux, v[MAX];

int main() {
	while (cin >> s) {
		memset(v, 0, sizeof(v));
		aux = s.size();
		cin >> n;
		v[0] = (s[0] == s[1]) ? 1 : 0;
		s += "$";
		for (int i = 1; i < aux; ++i) {
			v[i] = v[i-1];
			if (s[i] == s[i+1]) ++v[i];
		}
		while (n--) {
			cin >> l >> r;
			l -= 2, r -= 2;
			cout << v[r] - v[l] << endl;
		}
	}
}