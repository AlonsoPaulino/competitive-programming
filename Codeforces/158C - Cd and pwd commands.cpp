#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define pss pair<string, string>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pii>
#define vpss vector<pss>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n;
string command, path;
vs v;

string getans() {
	string ans = "/";
	for (int i = 0; i < sz(v); ++i) {
		ans += v[i], ans += "/";
	}
	return ans;
}

void pathToVector(string s, vs &tmp) {
	string aux = "";
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] != '/') {
			aux += s[i];
		} else {
			if (sz(aux) > 0) {
				tmp.pb(aux);
			}
			aux = "";
		}
	}
	if (sz(aux) > 0) tmp.pb(aux);
}

int main() {
	cin >> n;
	while (n--) {
		cin >> command;
		if (command == "pwd") {
			cout << getans() << "\n";
		} else {
			cin >> path;
			if (path[0] == '/') v.clear();
			vs aux; pathToVector(path, aux);
			for (int i = 0; i < sz(aux); ++i) {
				(aux[i] != "..") ? v.pb(aux[i]) : v.popb();
			}
		}
	}
	return 0;
}
