#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, val, aux, ans;
char c;
bool bs[MAX];

int main(){
	while ( cin >> n) {
		memset(bs, false, sizeof(bs));
		aux = ans = 0;
		for ( int i = 0 ; i < n; ++i ){
			cin >> c >> val;
			if ( c == '+' ){
				aux++;
				bs[val] = true;
			} else {
				if(!bs[val]) ans++;
				else aux--;
				bs[val] = false;
			}

			ans = max(ans, aux);
		}

		cout << ans << endl;
	}
}