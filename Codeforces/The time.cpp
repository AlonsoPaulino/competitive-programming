#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) x.size()
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define all(v) v.begin, v.end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<y<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int hh, mm, a, total;
char aux;

int main() {
	cin >> hh >> aux >> mm >> a;
	total = hh * 60 + mm + a;
	hh = (total / 60) % 24, mm = total % 60;
	if (hh < 10) cout << "0"; cout << hh << ":";
	if (mm < 10) cout << "0"; cout << mm << endl;
}