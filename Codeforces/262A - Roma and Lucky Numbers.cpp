#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int n,k;
	while(cin>>n>>k){
		int cont = 0;
		while(n--){
			string number; cin>>number;
			int l = number.size();
			int lucky_digits = 0;
			for(int i=0; i<l; ++i){
				if(number[i] == '4' || number[i] == '7'){
					lucky_digits++;
				}
			}
			if(lucky_digits <= k){
				cont++;
			}
		}
		cout<<cont<<endl;
	}	
}