#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	double n;
	while(cin>>n){
		double num_digits = floor(n*log10(2) + 1) ;
		printf("2^-%.0lf = %.3lfe-%.0lf\n",n, exp(num_digits - n*log10(2)),num_digits);
	}
}
