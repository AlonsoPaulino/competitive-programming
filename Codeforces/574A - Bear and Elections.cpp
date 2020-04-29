#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int n, val, ans;
bool flag;

bool my_sort(int a, int b){
	return a > b;
}

int main(){
	while ( cin >> n ){
		scanf("%d", &val);
		n--, flag = true;
		vector<int> v(n);
		ans = 0;
		
		for ( int i = 0 ; i < n; ++i ){
			scanf("%d", &v[i]);
			if(v[i] >= val) flag = false;
		}

		if(!flag){
			sort(v.begin(), v.end(), my_sort);

			int i = 0;
			int j = 0;
			
			while ( v[j] >= val ){
				if((j + 1) < n){
					while ( v[j] == v[j+1] ) j++;
					while ( v[j] > v[j+1] && v[j] >= val){
						for (int k = i; (k <= j && v[j] >= val); ++k){
							v[k]--;
							val++;
							ans++;
						}
					}	
				}else{
					for (int k = i; (k <= j && v[j] >= val); ++k){
							v[k]--;
							val++;
							ans++;
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}