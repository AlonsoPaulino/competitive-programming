#include <iostream>
using namespace std;

int botellas[9];

int contarMovimientos(int a,int b, int c){
	int retorno = 0;
	for(int i=0; i<9;i++){
		if(i!=a && i!=b && i!=c)
		retorno = retorno +  botellas[i];
	}	
	return retorno;
}

int retornarPosicion(int movimientos[],int num, int n){
	for(int i=0; i<n;i++){
		if(movimientos[i]==num) return i;
	}
	return -1;
}

main(){

	while(cin>>botellas[0]){
		for(int i=1; i<9;i++){
			cin>>botellas[i];
		}
		char posibilidades [6][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
		int movimientos[6];
		movimientos[0] = contarMovimientos(0,5,7);
		movimientos[1] = contarMovimientos(0,4,8);
		movimientos[2] = contarMovimientos(2,3,7); 
		movimientos[3] = contarMovimientos(2,4,6);
		movimientos[4] = contarMovimientos(1,3,8);
		movimientos[5] = contarMovimientos(1,5,6);

		int menor = movimientos[0];
		for(int i=1; i<6; i++){
			if(movimientos[i]<menor){ menor = movimientos[i];}
		}

		int pos = retornarPosicion(movimientos,menor,6);
		cout<<posibilidades[pos]<<" "<<menor<<endl;
		
	}	

}