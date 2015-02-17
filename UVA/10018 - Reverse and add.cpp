#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numeroCifras(long long p){
	int aux = p;
	int cont = 0;
	while(aux!=0){
		aux = aux/10;
		cont ++;
	}
	return cont;
}

long long invertir(long long p){
	long long numInvertido = 0;
	long long aux = p;
	long long l = numeroCifras(p);
	for(int i= (l-1); i>=0;i--){
		numInvertido = numInvertido + (aux%10)*pow(10,i);
		aux = aux/10;
	}
	return numInvertido;
}


bool palindromo(long long p){
	if(p == invertir(p)){
		return true;
	}else return false;
}

void resultado(long long p, vector<long long> &v){
	long long cont = 0;
	while(!palindromo(p)){
		int auxiliar = invertir(p);
		p = p + auxiliar;
		cont++;
	}
	v.push_back(cont);
	v.push_back(p);
}

int main(){
	int n;
	long long p;
	vector<long long> result;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>p;
		vector<long long> v;
		resultado(p,v);
		result.push_back(v[0]);
		result.push_back(v[1]);
		v.clear();
	}
	for(int i=0; i<result.size();i+=2){
		cout<<result[i]<<" "<<result[i+1]<<endl;
	}
}
