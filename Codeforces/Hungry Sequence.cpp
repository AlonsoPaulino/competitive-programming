#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#define MAX 10000010

using namespace std;

bitset<MAX> bs;

int n;

void sieve(){
	bs[0] = bs[1] = 0;
	for(long long i = 2; i < MAX; ++i){
		if(bs[i]){
			for(long long j = i*i; j < MAX; j+=i){
				bs[j] = 0;
			}
		}
	}
}

int main(){

	bs.set();
	sieve();

	while(cin>>n){

		int cont = 0;

		for(int i = 0; (i < MAX) && cont < n; i++){
			
			if(bs[i]){
				cout<<i;
				if(cont < n) cout<<" ";	
				cont++;
			} 
		}
	}
}
