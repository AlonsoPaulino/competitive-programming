#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>
#define mp make_pair
#define pb push_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

map<char, int> m;
int n;
string s;
ull aux;

void init() {
	m['A'] = 2;
	m['B'] = 2;
	m['C'] = 2;
	m['D'] = 3;
	m['E'] = 3;
	m['F'] = 3;
	m['G'] = 4;
	m['H'] = 4;
	m['I'] = 4;
	m['J'] = 5;
	m['K'] = 5;
	m['L'] = 5;
	m['M'] = 6;
	m['N'] = 6;
	m['O'] = 6;
	m['P'] = 7;
	m['Q'] = 7;
	m['R'] = 7;
	m['S'] = 7;
	m['T'] = 8;
	m['U'] = 8;
	m['V'] = 8;
	m['W'] = 9;
	m['X'] = 9;
	m['Y'] = 9;
	m['Z'] = 9;
}

char toUp(char c) {
	if (c >= 'a' && c <= 'z') {
		return (char) (c - 'a' + 'A');
	}
	return c;
}

int main() {
	cin >> n;
	init();
	while (n--) {
		cin >> s;
		bool ans = 1;
		for (int i = 0; i < (sz(s)+1)/2 && ans; ++i) {
			int j = sz(s) - i - 1;
			if (m[toUp(s[j])] != m[toUp(s[i])]) {
				ans = 0;
			}
		}
		if (!ans) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}