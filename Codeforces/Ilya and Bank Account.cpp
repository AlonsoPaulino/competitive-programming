#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
	while (cin >> n) {
		a = n/10;
		b = ((int) n / 100)*10 + n % 10;
		cout << max(n, max(a, b)) << endl;
	}
}