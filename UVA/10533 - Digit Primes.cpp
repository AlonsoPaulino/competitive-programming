#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 1000001
using namespace std;

int v[MAX + 1];
int ans[MAX + 1];
int n, t1, t2;

int digitPrime(int num){
	int sum = 0;
	while(num > 0) sum += (num % 10), num /= 10;
	return sum;
}

void sieve(){
	memset(v, 1, sizeof(v));
	v[0] = v[1] = 0;
	for(long long i = 2; i <= MAX; ++i){
		if(v[i] > 0){
			v[i] = digitPrime(i);
			for(long long j = i*i; j <= MAX; j += i){
				v[j] = 0;
			}
		}
	}
}

void calculateAns(){
	ans[0] = ans[1] = 0;
	long long acum = ans[0] + ans[1];
	for(int i = 2; i <= MAX; ++i){
		acum += (v[v[i]] > 0);
		ans[i] = acum;
	}
}

int main(){
	
	sieve(), calculateAns();
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &t1, &t2);
		printf("%d\n", ans[t2] - ans[t1 - 1]);
	}

	return 0;
}