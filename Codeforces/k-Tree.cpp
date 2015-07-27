#include <bits/stdc++.h>
#define MAX 101
#define MOD 1000000007
using namespace std;

int v[MAX][2];
int n, k, d;

void suma(int &a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
}

void dp(){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(j > i) break;
			if(j < d){
				suma(v[i][0], v[i-j][0]);
				suma(v[i][1], v[i-j][1]);
			}else{
				suma(v[i][1], v[i-j][0]);
				suma(v[i][1], v[i-j][1]);
			}
		}
	}
}

int main(){
	while(cin>>n>>k>>d){
		for(int i = 1; i<=n ; ++i) v[i][0] = v[i][1] = 0;
		v[0][0] = 1;
		dp();
		cout<<v[n][1]<<endl;
	}
}