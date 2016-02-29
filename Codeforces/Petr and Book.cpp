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

int n, aux, ans;
int v[8];

int main() {
	while (cin >> n) {
		v[0] = aux = 0;
		for (int i = 1; i <= 7; ++i) {
			cin >> v[i];
			v[0] += v[i];
		}
		n = n % v[0];
		if (n > 0) {
			for (int i = 1; i <= 7; ++i) {
				aux += v[i];
				if (aux >= n) {
					ans = i;
					break;
				}
			}
		} else {
			for (int i = 7; i >= 1; i--) {
				if (v[i] > 0) {
					ans = i;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}