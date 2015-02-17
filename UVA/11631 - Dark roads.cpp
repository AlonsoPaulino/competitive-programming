#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int v[200005];

int find(int n){
	return (n == v[n])? n : v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

struct Edge{
	int origen;
	int destino;
	int peso;
};

vector<Edge> aristas(200005);

bool mysort(Edge e1, Edge e2){
	return e1.peso < e2.peso;
}

int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0 && n==0)return 0;
		else{
			unsigned long long suma = 0;
			for(int i = 0; i < m; ++i)v[i] = i;
			for(int i = 0; i < n; ++i){
				Edge e; cin>>e.origen>>e.destino>>e.peso;
				aristas[i] = e;
				suma+=e.peso;
			}
			unsigned long long suma_minima = 0;
			sort(aristas.begin(), aristas.begin()+n, mysort);
			for(int i = 0; i < n; ++i){
				if(find(aristas[i].origen)!=find(aristas[i].destino)){
					Union(aristas[i].origen, aristas[i].destino);
					suma_minima+=aristas[i].peso;
				}
			}
			cout<<suma-suma_minima<<endl;
		}
	}
}
