#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAX 1000005
using namespace std;

struct Edge{
	int origen;
	int destino;
	int peso;
};

vector<Edge> aristas(MAX + 10);

int v[MAX];
int n, k, m;

bool mysort(Edge e1, Edge e2){
	return e1.peso < e2.peso;
}

int find(int n){
	return (v[n] == n)? n : v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	bool first = true;
	while(cin>>n){
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < (n + 1); ++i)v[i] = i;
		for(int i = 0; i < n - 1; ++i){
			Edge e; cin>>e.origen>>e.destino>>e.peso;
			ans1+=e.peso;
		}
		cin>>k;
		for(int i = 0; i < k; ++i){
			Edge e; cin>>e.origen>>e.destino>>e.peso;
			aristas[i] = e;
		}
		cin>>m;
		for(int i = k; i < (m+k); ++i){
			Edge e; cin>>e.origen>>e.destino>>e.peso;
			aristas[i] = e;
		}	
		sort(aristas.begin(), aristas.begin() + (m+k), mysort);
		for(int i = 0; i < (m+k); ++i){
			if(find(aristas[i].origen) != find(aristas[i].destino)){
				Union(aristas[i].origen, aristas[i].destino);
				ans2+=aristas[i].peso;
			}
		}
		if(first){
			first = false;
			cout<<ans1<<endl<<ans2<<endl;
		}else{
			cout<<endl<<ans1<<endl<<ans2<<endl;
		}
	}
}
