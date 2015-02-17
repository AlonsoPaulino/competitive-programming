#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string.h>

using namespace std;
#define N 1005

bool v[N];
int s, t;

void criba (){
    memset (v, true, sizeof (v));
    v[0] = v[1] = false; 
    for (int i = 4; i < N; i += 2)v [i] = false;
    for (int i = 3; i * i <= N; i++) {
        if (v[i]) {
            for (int j = i*i; j < N; j += 2*i) v[j] = false;
        }
    }
}

struct Node{
	int val;
	int cant;
};

vector<int> primes[1001];
bool visitados[1001];

void init(){
	criba();
	for(int i = 1; i <= 1000; ++i){
		for(int j = 2; j < i; ++j){
			if(v[j] && ((i % j) == 0)){
				primes[i].push_back(j);
			}
		}
	}
}

int bfs(){
	memset(visitados, false, sizeof(visitados));
	queue<Node> Q;
	Node node; node.val = s, node.cant = 0;
	Q.push(node);
	while(!Q.empty()){		
		Node current_value = Q.front();
		Q.pop();
		int l = primes[current_value.val].size();
		for(int i = 0; i < l; ++i){
			Node aux; aux.val = current_value.val + primes[current_value.val][i]; 
			aux.cant = current_value.cant + 1;
			if(!visitados[aux.val]){
				if(aux.val < t){ 
					visitados[aux.val] = true;
					Q.push(aux);
				}else if(aux.val == t)return current_value.cant + 1;
			}
		}
	}
	return -1;
}


int main(){
	int caso = 1; init();
	while(cin>>s>>t){
		if(s==0 && t==0)return 0;
		else{
			if(t < s)cout<<"Case "<<caso<<": -1"<<endl;
			else if(t == s)cout<<"Case "<<caso<<": 0"<<endl;
			else cout<<"Case "<<caso<<": "<<bfs()<<endl;
		}
		caso++;
	}
}
