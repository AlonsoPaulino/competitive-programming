#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int menor(int val1, int val2){
	
	int r1 = sqrt(val1);
	int r2 = sqrt(val2);
	
	int min_area_val_1 = 10000005, min_area_val_2 = 10000005;

	int area_aux;
	
	for(int i = r1; i >= 1; i--){
		if(val1 % i == 0){
			int aux1 = i, aux2 = val1/aux1;
			area_aux = 2*(aux1*aux2 + aux1*val2 + aux2*val2);
			min_area_val_1 = min(area_aux, min_area_val_1);
		}
	}

	for(int i = r2; i >= 1 ; i--){
		if(val2 % i == 0){
			int aux1 = i, aux2 = val2/aux1;
			area_aux = 2*(aux1*aux2 + aux1*val1 + aux2*val1);
			min_area_val_2 = min(area_aux, min_area_val_2);
		}
	}

	return min(min_area_val_1,min_area_val_2);	
}

int main(){
	int c; cin>>c;
	while(c--){
		
		int n; cin>>n;
		if(n > 0){
			int r = sqrt(n);
			int answer = 10000005;
			int min_area_val;

			for(int i = r; i>=1 ; i--){
				if(n%i == 0){
					int aux_1 = i, aux_2 = n/i;
					int min_area_val = menor(aux_1, aux_2);
					answer = min(min_area_val,answer);
				}
			}
			cout<<answer<<endl;
		}else{
			cout<<0<<endl;
		}
	}
}
