#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int n, m, a, l, r;
int auxn, auxp;

int main() {
	while (cin >> n >> m) {
		auxn = auxp = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			(a > 0) ? auxp++ : auxn++;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &l, &r);
			int t = r - l + 1;
			if (t & 1) {
				printf("0\n");
			} else {
				t = t/2;
				if (t <= auxn && t <= auxp) {
					printf("1\n");
				} else {
					printf("0\n");
				}
			}
		}
	}
}