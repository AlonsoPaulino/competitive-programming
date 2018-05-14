#include <bits/stdc++.h>
#define sz(x) x.size()
#define DEBUG(x) cout<<#x<<" -> "<<x<<endl;
using namespace std;

int t, l;
string s, b, e;
string R = "miao.", F = "lala.";

int main() {
	cin >> t;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		l = sz(s);
		if (l > 4) {
			b = s.substr(0, 5);
			e = s.substr(l - 5, 5);
			if (b == R && e == F) {
				cout << "OMG>.< I don't know!" << endl;	
			} else {
				if (b == R) {
					cout << "Rainbow's" << endl;
				} else if (e == F) {
					cout << "Freda's" << endl;
				} else {
					cout << "OMG>.< I don't know!" << endl;	
				}
			}
		} else {
			cout << "OMG>.< I don't know!" << endl;
		}
	}
	return 0;
}
