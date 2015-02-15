#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int v[30005];
int v_count[30005];

int find(int n){
	return n==v[n]? n: v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	int T; cin>>T;
	while(T--){
		int n, m; cin>>n>>m;
		
		for(int i = 0; i <= n; ++i){
			v[i] = i; v_count[i] = 0;
		}

		for(int i = 0; i < m; ++i){
			int a, b; cin>>a>>b;	
			Union(a,b);
		}	

		for(int i = 0; i <= n; ++i){
			v_count[find(i)]++;
		}

		int ans = v_count[1];
		for(int i = 1; i <= n; ++i) ans = (v_count[i]>ans)?v_count[i]:ans;
		cout<<ans<<endl;
	}
}
