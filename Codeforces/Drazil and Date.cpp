#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll a,b,s;

int main(){
	while(cin>>a>>b>>s){
		
		ll min_way = abs(a) + abs(b);
		
		bool result = false;
		
		if(s >= min_way)
			if(((min_way & 1) && (s & 1)) || ((!(min_way & 1)) && (!(s & 1)))) 
				result = true;

		cout<<((result)?"Yes":"No")<<endl;
	}
}
