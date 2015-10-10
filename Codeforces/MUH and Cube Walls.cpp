#include <bits/stdc++.h>
#define MAX 2 * 100001
using namespace std;

int n, w, t[MAX], p[MAX], b[MAX], aux1, aux2, ans;

void KMP_table() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < w) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

void KMP_search() {
	int i = 1, j = 0;
	while (i < n) {
		if (t[i] == p[j] || j < 0) {
			i++, j++;
			if (j == w) {
				ans++;
				j = b[j];
			}
		} else {
			if (j >= 0) {
				j = b[j];
			}
		}
	}
}

int main() {
	while (cin >> n >> w) {
		ans = 0;
		cin >> aux1;
		t[0] = 0;
		for (int i = 1; i < n; ++i) {
			cin >> aux2;
			t[i] = aux2 - aux1;
			aux1 = aux2;
		}
		
		cin >> aux1;
		w--;
		for (int i = 0; i < w; ++i) {
			cin >> aux2;
			p[i] = aux2 - aux1;
			aux1 = aux2;
		}

		if (w == 0) {
			cout << n << endl;
		} else {
			KMP_table();
			KMP_search();
			cout << ans << endl;
		}
	}
}