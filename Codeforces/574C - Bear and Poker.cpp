#include <bits/stdc++.h>
using namespace std;

int n, a, val, aux;
bool ans;

int main(){
	while ( cin >> n ){
		ans = true;
		for ( int i = 0; i < n; ++i ){
			cin >> a;			
			if(ans){
				if( i == 0 ){
					val = a;
					while( val % 3 == 0 || val % 2 == 0){
						if(val % 3 == 0) val/=3;
						else if(val % 2 == 0) val/=2;
					}
				}else{
					aux = a;
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