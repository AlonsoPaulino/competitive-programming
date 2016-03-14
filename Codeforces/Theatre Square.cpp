#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll n, m, a;

int main() {
	while (cin >> n >> m >> a) {
		ll x = n/a;
		ll y = m/a;
		if (n % a) ++x;
		if (m % a) ++y;
		cout << x * y << endl;
	}
}