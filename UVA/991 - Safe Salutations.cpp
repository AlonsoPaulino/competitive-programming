#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> v(11);

void init(){
	v[0] = 1;
	for(int i = 1; i<11; i++){
		v[i] = v[i-1]*(2*i*((2*i) - 1))/((i+1)*i);
	}
}

int main(){
	init();
	int n; bool flag = false;
	while(cin>>n){
		if(flag)cout<<endl; 
		cout<<v[n]<<endl;
		flag = true;
	}
}

