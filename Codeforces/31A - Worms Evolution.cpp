#include <bits/stdc++.h>
#define MAX_N 101
#define MAX 1001
using namespace std;

int n, v[MAX_N], ansi, ansj, ansk;
vector<int> aux[MAX];
bool ans;

void init(){
	for (int i = 0; i < MAX; ++i){
		vector<int> indexs;
		aux[i] = indexs;
	}
}

int main(){
	while (cin >> n) {
		init(), ans = false;
		for (int i = 0; i < n; ++i){
			cin >> v[i];
			aux[v[i]].push_back(i);
		}

		for (int j = 0; j < n && !ans; ++j){
			for (int k = j + 1; k < n && !ans; ++k){
				int sum = v[j] + v[k];
				if(sum < MAX){
					if(aux[sum].size() > 0){
						for(int i = 0; i < aux[sum].size() && !ans; ++i){
							if(aux[sum][i] != j && aux[sum][i] != k){
								ansi = aux[sum][i] + 1, ansj = j + 1, ansk = k + 1;
								ans = true;
							}
						}
					}
				}
			}
		}	

		if(ans) cout << ansi << " " << ansj << " " << ansk;
		else cout << -1;

		endl(cout);
	}
}