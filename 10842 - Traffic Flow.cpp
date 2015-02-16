#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int v[105];

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

vector<Edge> aristas(10005);

bool mysort(Edge e1, Edge e2){
	return e1.peso > e2.peso;
}

int main(){
	int cases; cin>>cases;
	int n, m;
	for(int c = 1; c <= cases; c++){
		cin>>n>>m;
		for(int i = 0; i < n; ++i)v[i] = i;
		for(int i = 0; i < m; ++i){
				Edge e; cin>>e.origen>>e.destino>>e.peso;
				aristas[i] = e;
		}
		sort(aristas.begin(), aristas.begin()+m, mysort);
		int capacidad = aristas[0].peso;
		for(int i = 0; i < m; ++i){
			if(find(aristas[i].origen)!=find(aristas[i].destino)){
				Union(aristas[i].origen, aristas[i].destino);
				capacidad = min(aristas[i].peso, capacidad);							
			}
		}
		cout<<"Case #"<<c<<": "<<capacidad<<endl;
	}
}
