#include <bits/stdc++.h>
#define vi vector<int>
#define sz(x) x.size()
#define pb push_back
#define test() cout<<"Por qué no funciona :c"<<endl;
#define DEBUG(x) cout<<#x<<" -> "<<x<<endl;
#define DEBUG2(x, y) cout<<#x<<" -> "<<x<<" & "<<#y<<" -> "<<y<<endl;
typedef unsigned long long ull;
using namespace std;

ull li, ls, ans;

int main() {
	while (cin >> li >> ls) {
		ans = 0;
		for (int i = 1; i < 62; ++i) {
			ull max = pow(2, i) - 1;
			ull limit = pow(2, i - 1);
			ull aux = 1;
			while (aux < limit) {
				ull val = max - aux;
				if (val >= li && val <= ls) ans++;
				if (val < li) break;
				aux <<= 1;
			}
		}
		cout << ans << endl;
	}
}