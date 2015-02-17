#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

struct point{
	int f,c, altura;
};

int triangle_number = 1;
int n; 
int max_altura;
int df[] = {1,-1};
char triangle[1024][1024];

void bfs(int script_f, int script_c, int orientation){
	queue<point> Q;
	point script; script.f = script_f; script.c = script_c;
	script.altura = 1;
	if(max_altura == 0)max_altura = 1;
	Q.push(script);
	while(!Q.empty()){
		point head = Q.front();
		Q.pop();
		int i = orientation;
		point aux; aux.f = head.f + df[i]; aux.c = head.c; aux.altura = head.altura;
		if(aux.f<=n&&aux.c<=2*n-1&&aux.f>=1&&aux.c>=1){
			if(triangle[aux.f][aux.c] == '-'){
				int cont = 1;
				bool flag = true;
				while(cont<=aux.altura && flag){
					if(triangle[aux.f][aux.c-cont]!= '-' || triangle[aux.f][aux.c+cont]!='-'){
						flag = false;
					}
					cont++;
				}
				if(flag){
					aux.altura++;
					if(aux.altura>max_altura)max_altura = aux.altura;
					Q.push(aux);
				}
			}
		}
	}
}
	
int main(){
	while(cin>>n){
		if(n==0)return 0;
		max_altura = 0;
		memset(triangle,'#',sizeof(triangle));
		int cant = 2*n -1, aux = 0;
		for(int i=1; i<=n; ++i){
			for(int j=1+aux; j<=cant+aux; ++j){	
				cin>>triangle[i][j];
			}
			cant-=2;
			aux++;
		}
		cant = 2*n-1;
		for(int i=1; i<=n; ++i){
			for(int j=1;j<=cant;++j){
				if(triangle[i][j] == '-'){
					if(i&1){
						if(j&1)bfs(i,j,1);
						else bfs(i,j,0);
					}else{
						if(j&1)bfs(i,j,0);
						else bfs(i,j,1);
					}
				}
			}
		}
		cout<<"Triangle #"<<triangle_number<<endl;
		cout<<"The largest triangle area is "<<(max_altura)*(max_altura)<<"."<<endl;
		cout<<endl;
		triangle_number++;
	}
}