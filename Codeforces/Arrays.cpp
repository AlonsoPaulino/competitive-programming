#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int a[MAX];
int b[MAX];
int na, nb, k, m;

int main(){
	while( cin >> na >> nb){
		cin >> k >> m;
		for(int i = 0; i < na; ++i) cin >> a[i];
		for(int i = 0; i < nb; ++i) cin >> b[i];
		
		int amax = a[k - 1];
		int cont = 0;
		for(int i = 0; (i < nb) && (cont < m); ++i){
			if(b[i] > amax){
				cont++;
			}
		}

		if(cont == m) cout << "YES";
		else cout << "NO";

		endl(cout);
	}
}
