#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int t; cin>>t;
	for(int i = 0; i < t; ++i){
		  int a, b; cin>>a>>b;
		  (!(a&1))?a--:a-=2; (!(b&1))?b--:b+0;
		  int n1 = (a+1)/2, n2 = (b+1)/2;
		  cout<<"Case "<<i + 1<<": " <<(n2*n2) - (n1*n1)<<endl;
	}
}
