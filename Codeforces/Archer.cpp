#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

int main() {
	while (cin >> a >> b >> c >> d) {
		double aux1 = (1 - (double) (a/b)), aux2 = (1 - (double) (c/d));
		printf("%.16lf\n", (double) (a / b) * (double) (1 / (1 - (aux1 * aux2))));
	}
}