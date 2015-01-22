#include <iostream>
using namespace std;
int multiplicar(int a, int b, int m){
	return ((a%m)*(b%m))%m;
}

int elevar(int num, int exp, int m){
	if(exp==0) return 1;
	else if(exp==1)return num;
	else{
		if(exp%2==0) return elevar(multiplicar(num,num,m),(exp/2),m);
		else return multiplicar(elevar(
					multiplicar(num,num,m),(exp/2),m),num,m);
	}
}

main(){
	int b,p,m;
	while(cin>>b>>p>>m) cout<<elevar(b,p,m)<<endl;
}