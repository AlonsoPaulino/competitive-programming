#include <bits/stdc++.h>
#define MIN 30000000
#define MAX 40000000
using namespace std;

bitset<MAX + 1> bs;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	bs[2] = 1;
	for(long long  i = 4; i <= MAX ; i+=2) bs[i] = 0;
	for(long long i = 3; i <= MAX; i++){
		if(bs[i]){
			for(long long j = i*i; j <= MAX; j+=i){
				bs[j] = 0;
			}
		}
	}
}

int main(){
	sieve();
	for(int i = MIN; i <= MAX; i++){
		if(bs[i]){
			printf("%d\n", i);
		}
	}
}