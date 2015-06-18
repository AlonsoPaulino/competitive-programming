#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

unsigned long long n,k;

int main(){

	while(cin>>n>>k){

		unsigned long long max = (!(n&1))? (n/2) : ((n/2) + 1);

		if(k > max){

			unsigned long long aux = k - max;
			cout<<2*aux<<endl;

		}else cout<<(2*k - 1)<<endl;

	}
}
