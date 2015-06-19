#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

int main(){
	while(cin>>n){
		
		if(n&1) cout<<-1;
		else{
			for(int i = 1; i <= n; i+=2){
				if(i!=1) cout<<" ";
				cout<<i+1<<" "<<i;
			}
		}

		cout<<endl;
	}
}
