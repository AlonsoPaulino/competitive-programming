#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 105
using namespace std;

struct Edge{
	int origen;
	int destino;
	double peso;
};

struct Point{
	double x;
	double y;
}points[MAX];

int v[MAX];
vector<Edge> aristas;

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
	int t; cin>>t;
	bool first = false;
	while(t--){
		int n; cin>>n;
		for(int i = 0; i < n ; ++i){
			Point p; cin>>p.x>>p.y;
			points[i] = p;
			v[i] = i;
		}
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				if(i!=j){
					Edge e; e.origen = i, e.destino = j;
					e.peso = sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x) + 
						(points[i].y - points[j].y)*(points[i].y-points[j].y));
					aristas.push_back(e);
				}
			}
		}
		sort(aristas.begin(), aristas.end(), mysort);
		int l = aristas.size();
		double ans = 0;
		for(int i = 0; i < l ; ++i){
			if(find(aristas[i].origen) != find(aristas[i].destino)){
				Union(aristas[i].origen, aristas[i].destino);
				ans += aristas[i].peso;
			}
		}
		if(first)cout<<endl;
		first = true;
		printf("%.2lf\n",ans);
		aristas.clear();
	}
}	
