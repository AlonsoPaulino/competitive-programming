#include <bits/stdc++.h>
using namespace std;

string s;
int h, m;
double x, y;

int main(){
	while ( cin >> s ){
		h = (s[0] - '0') * 10 + (s[1] - '0');
		m = (s[3] - '0') * 10 + (s[4] - '0');

		if( h > 12 ) h -= 12;

		x = 360 * h / 12;
		y = 360 * m / 60;

		x = (x == 360) ? 0 : x;
		y = (y == 360) ? 0 : y;

		x += (m * 360 / 720.0);
		cout << x << " " << y << endl;
	}
}