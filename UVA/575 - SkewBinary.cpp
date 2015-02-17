#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int retornarSuma(string s){
    int l = s.size();
    int pos = 1;
    long long suma = 0;
    for(int i=l-1; i>=0; i--){
 	int a = s[i]-'0';
	suma+=a*((pow(2,pos))-1);
	pos++;
    }
    return suma;
}

main(){
	string s;
	vector<string> v;
	while(cin>>s){
		if(!((s.size()==1) && (s[0]-'0'==0))){
			v.push_back(s);
		}else{
			for(int i = 0; i<v.size();i++){
				cout<<retornarSuma(v[i])<<endl;
			}
			v.clear();
		}
	}
}
