#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout<<#x<<"->"<<x<<endl;
using namespace std;

ll a, b, n;

int main() {
	while (cin >> a >> b >> n) {
		if (a != 0) {
			float q = b/a;
			if (q - (ll)q == 0) {
				float ans = pow(abs(b/a), (float) 1/n);
				if (ans - (ll)ans == 0) {
					if (b/a < 0) {
						if (n & 1) {
							cout << "-" << ans << endl;
						} else {
							cout << "No solution" << endl;
						}
					} else {
						cout << ans << endl;
					}
				} else {
					cout << "No solution" << endl;
				}	
			} else {
				cout << "No solution" << endl;	
			}
		} else {
			if (b == 0) {
				cout << "1" << endl;
			} else {
				cout << "No solution" << endl;
			}
		}
	}
}