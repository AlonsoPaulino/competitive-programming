#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge{
	int origen;
	int destino;
	double peso;
};

int v[1005];
vector<Edge> aristas(25005);

int find(int n){
	return (v[n] == n)? n : v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

bool mysort(Edge e1, Edge e2){
	return e1.peso < e2.peso;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0)return 0;
		for(int i = 0; i < n; ++i)v[i] = i;
		for(int i = 0; i < m; ++i){
			Edge e; cin>>e.origen>>e.destino>>e.peso;
			aristas[i] = e;
		}
		sort(aristas.begin(), aristas.begin()+m, mysort);
		vector<int> answer;
		for(int i = 0; i < m ; ++i){
			if(find(aristas[i].origen) != find(aristas[i].destino)){
				Union(aristas[i].origen, aristas[i].destino);
			}else{
				answer.push_back(aristas[i].peso);
			}
		}
		sort(answer.begin(), answer.end());
		int l = answer.size();
		if(l < 1){
			cout<<"forest"<<endl;
		}else{
			bool first = true;
			for(int i = 0; i < l; ++i){
				if(!first)cout<<" ";
				first = false;
				cout<<answer[i];
			}
			cout<<endl;
		}
		answer.clear();
	}
}	
