#include <bits/stdc++.h>
#define MAX 52
using namespace std;

int n, m, cij, a, b, c;

int v[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; ++i) {
		v[i][0] = 0;
		v[0][i] = 0;
	}
}

bool valid(int aux1, int aux2, int aux3) {
	if (aux1 == a && aux2 == b && aux3 == c) return true;
	if (aux1 == a && aux2 == c && aux3 == b) return true;
	if (aux1 == b && aux2 == a && aux3 == c) return true;
	if (aux1 == b && aux2 == c && aux3 == a) return true;
	if (aux1 == c && aux2 == a && aux3 == b) return true;
	if (aux1 == c && aux2 == b && aux3 == a) return true;
	return false;
}

int ansV(int ver[]) {
	int ans = 0;
	for (int i = 1; i <= n-2; ++i) {
		for (int j = i+1; j <= n-1; ++j) {
			int aux1 = 0, aux2 = 0, aux3 = 0;
			for (int w = 1; w <= i; ++w) aux1 += ver[w];
			for (int w = i+1; w <= j; ++w) aux2 += ver[w];
			for (int w = j+1; w <= n; ++w) aux3 += ver[w];
			if (valid(aux1, aux2, aux3)) ++ans;
		}
	}
	return ans;
}

int ansH(int hor[]) {
	int ans = 0;
	for (int i = 1; i <= m-2; ++i) {
		for (int j = i+1; j <= m-1; ++j) {
			int aux1 = 0, aux2 = 0, aux3 = 0;
			for (int w = 1; w <= i; ++w) aux1 += hor[w];
			for (int w = i+1; w <= j; ++w) aux2 += hor[w];
			for (int w = j+1; w <= m; ++w) aux3 += hor[w];
			if (valid(aux1, aux2, aux3)) ++ans;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt" ,"r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while (cin >> n >> m) {
		int ver[n+1];
		int hor[m+1];
		memset(ver, 0, sizeof(ver));
		memset(hor, 0, sizeof(hor));
		for (int i = 1; i <= n; ++i) {
			int vaux = 0;
			for (int j = 1; j <= m; ++j) {
				cin >> v[i][j];
				vaux += v[i][j];
			}
			ver[i] = vaux;
		}
		for (int j = 1; j <= m; ++j) {
			int haux = 0;
			for (int i = 1; i <= n; ++i) {
				haux += v[i][j];
			}
			hor[j] = haux;
		}
		cin >> a >> b >> c;
		cout << ansV(ver) + ansH(hor) << endl;
	}
}