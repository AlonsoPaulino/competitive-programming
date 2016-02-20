#include <bits/stdc++.h>
#define DEBUG(x) cout << #x <<" -> " << x << endl;
#define test() cout << "hola papa" << endl;
using namespace std;

int h, m, tl, auxh, auxm;
char c;

int main() {
	while (cin >> h >> c >> m) {
		cin >> tl;
		auxh = tl / 60;
		auxm = tl % 60;
		h += auxh;
		m += auxm;
		if (m >= 60) m -= 60, ++h;
		h = h % 24;
		if (h < 10) cout << "0";
		cout << h << ":";
		if (m < 10) cout << "0";
		cout << m << endl;
	}
}
