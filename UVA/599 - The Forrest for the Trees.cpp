#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAX 30
using namespace std;

int v[MAX];
bool points[MAX];

int find(int n){
	return (v[n] == n)? n: v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

int toInt(char c){
	return c - 'A' + 1;
}

int main(){
	int T; cin>>T; bool flag = false;
	while(T--){
		string s; 
		for(int i = 0; i < MAX ; ++i) v[i] = i, points[i] = false;
		while(!flag && cin>>s){
			if(s[0]!='*'){
				char a = s[1], b = s[3]; 
				Union(toInt(a), toInt(b));
			}else flag = true;
		}

		string sp; cin>>sp;
		int l = sp.size();
		for(int i = 0; i < l; i+=2){
			points[toInt(sp[i])] = true;
		} 

		int trees = 0, acorns = 0;
		for(int i = 0; i < MAX ; ++i){
			if(points[i]){
				if(find(i) == i){
					bool acorn = true;
					for(int j = 0; j < MAX && acorn; ++j){
						if(points[i] && j!=i){
							if(find(j) == i) acorn = false;
						}
					}
					acorn? acorns++:trees++;
				}
			}
		}
		cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
		flag = false;
	}
}
