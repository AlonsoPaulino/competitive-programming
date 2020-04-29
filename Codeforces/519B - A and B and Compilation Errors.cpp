#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
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

int n, aux, ans1, ans2;

int main() {
	cin >> n;
	mii m1, m2;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		++m1[aux];
	}
	for (int i = 0; i < n-1; ++i) {
		cin >> aux;
		++m2[aux], --m1[aux];
	}
	for (int i = 0; i < n-2; ++i) {
		cin >> aux;
		--m2[aux];
	}
	mii::iterator it1 = m1.begin();
	mii::iterator it2 = m2.begin();
	for (it1; it1 != m1.end(); ++it1) if(it1->second == 1) ans1 = it1->first;
	for (it2; it2 != m2.end(); ++it2) if(it2->second == 1) ans2 = it2->first;
	printf("%d\n%d\n", ans1, ans2);
}