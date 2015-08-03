#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char s[1000001];
int n, i , j, l, li, ls, c = 1;

int main(){

	while(gets(s)){
		
		scanf("%d", &n);
		l = strlen(s);
		if(l == 0) break;

		printf("Case %d:\n", c);

		for(int aux = 1;  aux <= n; ++aux){
			scanf("%d %d", &i, &j);
			li = min(i,j), ls = max(i, j);
			bool ans = true;
			
			for(int k = li; (k < ls && ans); ++k) if(s[k] != s[k+1]) ans = false;
			if(ans) printf("Yes\n"); else printf("No\n");
		}

		c++;

		getchar();
	}

	return 0;
}