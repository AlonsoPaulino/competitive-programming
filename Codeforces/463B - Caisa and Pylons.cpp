#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#define MAX 100005	

using namespace std;

int n;
vector<int> v(MAX);

int main(){
	
	while(cin>>n){
		
		int energy = 0;
		int additional = 0;
		
		v[0] = 0;

		for(int i = 1; i <= n; ++i){ 
			cin>>v[i];	
			int diff = v[i-1] - v[i];
			energy += diff;
			if(energy < 0){
				additional += abs(energy);
				energy = 0;
			} 
		}

		cout<<additional<<endl;
	}
}
