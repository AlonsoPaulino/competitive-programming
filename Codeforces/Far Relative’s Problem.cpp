#include <bits/stdc++.h>
#define MAX 367
#define vi vector<int>
using namespace std;

int n, li, ls, m[MAX], f[MAX];
char g;

int main() {
	while(cin >> n) {
		int ans = 0, aux = 0;
		memset(m, 0, sizeof(m));
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i) {
			cin >> g >> li >> ls;
			if (g == 'M') {
				for (int i = li; i <= ls; ++i) ++m[i];
			} else {
				for (int j = li; j <= ls; ++j) ++f[j];
			}
		}
		for (int i = 1; i < MAX; ++i) {
			aux = 0;
			aux += (2 * min(m[i], f[i]));
			if (aux > ans) ans = aux;
		}
		cout << ans << endl;
	}
	return 0;
}