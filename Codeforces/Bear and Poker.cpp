#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, a, v[MAX], val, aux;
bool ans;

int main(){
	while ( cin >> n ){
		ans = true;
		for ( int i = 0; i < n; ++i ){
			cin >> v[i];			
			if(ans){
				if( i == 0 ){
					val = v[i];
					while( val % 3 == 0 || val % 2 == 0){
						if(val % 3 == 0) val/=3;
						else if(val % 2 == 0) val/=2;
					}
				}else{
					aux = v[i];
					while( aux % 3 == 0|| aux % 2 == 0){
						if(aux % 3 == 0) aux/=3;
						else if(aux % 2 == 0) aux/=2;
					}

					if(aux != val) ans = false;
				}
			}
		}

		if(ans) cout << "Yes"; else cout << "No";
		endl(cout);
	}
}