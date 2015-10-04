#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, v[MAX], p, d, ans, cont;
bool aux[MAX];

int main() {
	while (cin >> n) {
		ans = p = cont = 0;
		memset(aux, false, sizeof(aux));
		for (int i = 0; i < n; ++i) cin >> v[i];
		d = 1;
		while (cont != n) {
			if (d) {
				for (int i = 0; i < n; ++i) {
					if (!aux[i]) {
						if (p >= v[i]) {
							aux[i] = true;
							p++;
							cont++;
						}
					}
				}
			} else {
				for (int i = (n-1); i >= 0; --i) {
					if (!aux[i]) {
						if (p >= v[i]) {
							aux[i] = true;
							p++;
							cont++;
						}
					}	
				}
			}
			
			if (cont != n) {
				ans++;
				d = !d;
			}	
		}

		cout << ans << endl;
	}
}
