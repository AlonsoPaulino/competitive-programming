#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int num;
	double u,v,t,s,a;
	int i = 1;
	while(cin>>num){
		if(num==0)return 0;
		else{
			if(num == 1){
				cin>>u>>v>>t;
				a = (double)((v-u)/t);	
				s = (double)((u*t) + (a*t*t)/2);
				printf("Case %d: %.3f %.3f\n", i,s,a);
			}else if(num == 2){
				cin>>u>>v>>a;
				t = (double)((v-u)/a);
				s = (double)((u*t) + ((a*t*t)/2));
				printf("Case %d: %.3f %.3f\n", i,s,t);
			}else if(num == 3){
				cin>>u>>a>>s;
				v = (double)sqrt((u*u) + (2*a*s));
				t = (double)((v-u)/a);
				printf("Case %d: %.3f %.3f\n", i,v,t);
			}else if(num == 4){
				cin>>v>>a>>s;
				u = (double)sqrt(((v*v) - (2*a*s)));
				t = (double)((v-u)/a);
				printf("Case %d: %.3f %.3f\n", i,u,t);
			}
		i++;
		}
	}

}
