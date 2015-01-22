#include <iostream>
#include <sstream>
using namespace std;

string invertir(string a){
	string aux = "";
	int l = a.size();
	for(int i=l-1; i>=0; i--){
		aux+=a[i];
	}
	return aux;
}

int main(){
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		string aux;
		int i=0;
		while(ss>>aux){
			if(i)cout<<" ";
			cout<<invertir(aux);
			i = 1;
		}	
		endl(cout);
	}
}
