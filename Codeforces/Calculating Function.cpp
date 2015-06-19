#include <iostream>
#include <cmath>

using namespace std;

unsigned long long n;

int main(){
	while(cin>>n){
		unsigned long long result = (n+1)/2;
		if(n&1) cout<<"-"; cout<<result<<endl;
	}
}
