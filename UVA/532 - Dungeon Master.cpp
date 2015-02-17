#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 35
using namespace std;

char m[MAX][MAX][MAX];
bool visitado[MAX][MAX][MAX];
int d[] = {-1,1};
int l, r, c;

struct Point{
	int time;
	int x;
	int y;
	int z;
};

bool isValid(Point p){
	if(p.x >= 0 && p.x <c && p.y >= 0 && p.y < r && p.z >= 0 && p.z <l){
		if(m[p.z][p.y][p.x] != '#' && !visitado[p.z][p.y][p.x])return true;
	}
	return false;
}


int dfs(Point inicio){
	memset(visitado, false, sizeof(visitado));
	queue<Point> Q;
	Q.push(inicio);
	while(!Q.empty()){
		Point current = Q.front();
		Q.pop();
		for(int i = 0; i < 2; ++i){
			Point px, py, pz;
			px.x = current.x + d[i], px.y = current.y, px.z = current.z, px.time = current.time + 1;
			py.y = current.y + d[i], py.x = current.x, py.z = current.z, py.time = current.time + 1;
			pz.z = current.z + d[i], pz.x = current.x, pz.y = current.y, pz.time = current.time + 1;
			if(isValid(px)){
				if(m[px.z][px.y][px.x] == 'E') return px.time;
				else{
					visitado[px.z][px.y][px.x] = true;
					Q.push(px);
				}
			}
			if(isValid(py)){
				if(m[py.z][py.y][py.x] == 'E') return py.time;
				else{
					visitado[py.z][py.y][py.x] = true;
					Q.push(py);
				} 
			}
			if(isValid(pz)){
				if(m[pz.z][pz.y][pz.x] == 'E') return pz.time;
				else{
					visitado[pz.z][pz.y][pz.x] = true;
					Q.push(pz);
				}
			}
		}
	}
	return -1;
}	

int main(){
	Point inicio;
	while(cin>>l>>r>>c){
		if(l == 0 && r == 0 && c ==0)return 0;
		for(int i = 0; i < l; i++){ 		
			for(int j = 0; j < r; j++){
				for(int k = 0; k < c; k++){
					cin>>m[i][j][k];
					if(m[i][j][k] == 'S') inicio.time = 0, inicio.z = i, inicio.y = j, inicio.x = k;
				}
			}
		}
		int ans = dfs(inicio);
		if(ans > 0)cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else cout<<"Trapped!"<<endl;
	}
}