#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) x.size()
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define all(v) v.begin, v.end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string s;

int scmp(string a, string b) {
	if (sz(a) < sz(b)) return -1;
	if (sz(a) == sz(b)) {
		if (a < b) return -1;
		if (a == b) return 0;	
	}
	return 1;
}

int main() {
	while (cin >> s) {
		if (s[0] == '-') {
			s.erase(0, 1);
			if (scmp(s, "128") <= 0) {
				cout << "byte" << endl;
			} else if (scmp(s, "32768") <= 0) {
				cout << "short" << endl;
			} else if (scmp(s, "2147483648") <= 0) {
				cout << "int" << endl;
			} else if (scmp(s, "9223372036854775808") <= 0) {
				cout << "long" << endl;
			} else {
				cout << "BigInteger" << endl;
			}
		} else {
			if (scmp(s,  "127") <= 0) {
				cout << "byte" << endl;
			} else if (scmp(s, "32767") <= 0) {
				cout << "short" << endl;
			} else if (scmp(s, "2147483647") <= 0) {
				cout << "int" << endl;
			} else if (scmp(s, "9223372036854775807") <= 0) {
				cout << "long" << endl;
			} else {
				cout << "BigInteger" << endl;
			}
		}
	}
}