#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << endl;
		while (next_permutation(s.begin(), s.end())) {
			cout << s << endl;
		}
		cout << endl;
	}
	return 0;
}