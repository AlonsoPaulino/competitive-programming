#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

vector<int> v(27);

int find(int n){
	return n==v[n]? n: v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	
	int T; cin>>T;
	
	while(T--){
		string edges; cin>>edges;  
		int length = edges[0] -'A' + 1;
		
		for(int i=0; i<length; ++i)v[i] = i;
		
		getline(cin,edges);
		
		while(getline(cin,edges)){
			if(edges.size() == 0) break;
			char node1 = edges[0], node2 = edges[1];
			int val1 = node1 - 'A', val2 = node2 - 'A';
			
			Union(val1, val2);
		}
		
		set<int> raiz;
			
			for(int i=0; i<length; ++i){
				raiz.insert(find(i));
			}

		cout<<raiz.size()<<endl;
		if(T!=0)cout<<endl;
	}
}
