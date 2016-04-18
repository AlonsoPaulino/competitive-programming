#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1000000001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

char c;
int t, n, ci, cj, success, unsuccess;
vi v(MAX);

int find(int x) {
	return (x == v[x]) ? x : v[x] = find(v[x]);
}

int join(int x, int y) {
	v[find(x)] = find(y);
}

void init() {
	for (int i = 0; i <= n; ++i) {
		v[i] = i;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		success = unsuccess = 0;
		scanf("\n%d\n", &n), init();
		string s;
		while (1) {
			if (!getline(cin, s) || s.empty()) break;
			sscanf(s.c_str(), "%c %d %d", &c, &ci, &cj);
			if (c == 'c') {
				join(ci, cj);
			} else {
				if (find(ci) == find(cj)) {
					++success;
				} else {
					++unsuccess;
				}
			}
		}
		if (t > 0) {
			printf("%d,%d\n\n", success, unsuccess);
		} else {
			printf("%d,%d\n", success, unsuccess);
		}
	}
}

