#include <bits/stdc++.h>
#define vi vector<int>
#define sz(x) x.size()
#define pb push_back
#define test() cout<<"Por qué no funciona :c"<<endl;
#define DEBUG(x) cout<<#x<<" -> "<<x<<endl;
#define DEBUG2(x, y) cout<<#x<<" -> "<<x<<" & "<<#y<<" -> "<<y<<endl;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

string s;
int n, ans;

int main() {
	while (cin >> n >> s >> s) {
		if (s == "week") {
			if (n == 5 || n == 6) {
				ans = (366) / 7 + 1;
			} else {
				ans = (366) / 7;
			}
		} else {
			if (n == 31) ans = 7;
			if (n == 30) ans = 11;
			if (n <= 29) ans = 12;
		}
		cout << ans << endl;
	}
}