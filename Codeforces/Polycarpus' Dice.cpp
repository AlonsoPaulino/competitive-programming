#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 2*100005

using namespace std;

typedef unsigned long long ull;

vector<ull> v(MAX);

ull n, s, total_sum = 0;

int main(){
	while(cin>>n>>s){

		ull result = 0;
	
		for(ull i = 0; i < n ; ++i){
			cin>>v[i];
			total_sum += v[i];
		}

		if(n != 1){

			for(ull i = 0; i < n; ++i){
				ull current_sum = total_sum - v[i];
				ull min_value, max_value;
				if(current_sum >= s) min_value = 1;
				else min_value = s - current_sum;
				max_value = min(v[i], (s - (n-1)));
				cout<<(min_value - 1) + (v[i] - max_value);
				if(i < (n-1)) cout<<" ";
			}

		}else{

			cout<<v[0] - 1;

		}

		endl(cout);
	}
}
