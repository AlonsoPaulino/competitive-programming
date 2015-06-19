#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n,a,b;

int main(){
	while(cin>>n>>a>>b){
		int x1 = a;
		int x2 = n - b - 1;
		cout<<n-max(x1,x2)<<endl;
	}
}
