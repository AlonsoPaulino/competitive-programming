#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

using namespace std;
#define N 1000003
bool v[N];

void criba (){
    memset (v, true, sizeof (v));
    v [0] = v [1] = false;
 
    for ( int i = 4; i < N; i += 2 )
        v [i] = false;
 
    for ( int i = 3; i * i <= N; i++ ) {
        if ( v [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                v [j] = false;
        }
    }
}

int main(){
	criba();
	int n, m;
	while(cin>>n) {
		if(n == 0)return 0;
		else{
			bool exists = false;
			cout<<n<<":"<<endl;
			for(int i = n; i>=n/2 && !exists ; --i){
				if(v[i]){
					if(v[n-i]){
						exists = true;
						cout<<n-i<<"+"<<i<<endl;
					}
				}
			}
			if(!exists)cout<<"NO WAY!"<<endl;
		}
	}
}
