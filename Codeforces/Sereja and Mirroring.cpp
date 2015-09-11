#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int m, n, v[MAX][MAX], ans, aux;

bool check(int aux){
	for (int i = 0; i < aux/2; ++i){
		for (int j = 0; j < m; ++j){
			if( v[i][j] != v[(aux - 1 - i)][j]) return false;
		}
	}
	return true;
}

int main(){
	while (cin >> n >> m) {
		ans = n;

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> v[i][j];
			}
		}

		if ( !(n & 1)){
			aux = n;
			while (aux > 1 && !(aux & 1)){
				if (check(aux)){
					ans = aux/2;
					aux >>= 1;
				}else {
					break;
				}
			}
		}

		cout << ans << endl;
	}
}
