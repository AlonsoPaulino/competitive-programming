#include <bits/stdc++.h>
using namespace std;

int n;
bool b[10];

bool checkDivisor(int num){
	while(num != 0){
		int aux = num % 10;
		num /= 10;
		if(b[aux]) return true;
	}

	return false;
}

void init(){
	memset(b, 0, sizeof(b));
	int num = n;
	while(num != 0){
		int aux = num % 10;
		num /= 10;
		b[aux] = 1;
	}
}

int main(){
	while (cin >> n){
		init();
		int cont = 0;
		int i;

		for(i = 1; i*i < n; ++i){
			if(n % i == 0){
				if(checkDivisor(i)) cont++;
				if(checkDivisor(n/i)) cont++;
			}
		}

		if(i*i == n){
			if(checkDivisor(i)) cont++;
		}

		cout << cont <<endl;
	}
}
