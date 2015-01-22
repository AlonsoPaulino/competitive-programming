#include <iostream>
using namespace std;
int contar(int n){
	int cont=1;
	while(n!=1){
		if(n%2!=0) n=((3*n)+1);
		else n = n/2;
		cont++;
	}
	return cont;
}

main(){
	int i,j,value,mayor;
	while(cin>>i>>j){
		int li,lm;
		if(i>j){
			li=j;
			lm=i;
		}else {
			li=i; 
			lm=j;
		}
		mayor = contar(li);
		for(int k=li+1; k<=lm ;k++){
			value = contar(k);
			if(value>mayor) mayor = value;
		}
		cout<<i<<" "<<j<<" "<<mayor<<endl;
	}
}