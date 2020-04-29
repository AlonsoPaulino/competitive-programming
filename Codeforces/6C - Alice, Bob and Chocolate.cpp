#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, a, b, ta, tb, ans_a, ans_b, v[MAX];

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i) cin >> v[i];
		
		a = 0, b = n - 1, ta = tb = ans_a = ans_b = 0;
		
		while (a <= b){
			if (ta < tb){
				ta += v[a];
				a++;
				ans_a ++;
			}else if (tb < ta){
				tb += v[b];
				b--;
				ans_b++;
			}else{
				if (a != b){
					ta += v[a];
					tb += v[b];
					a++, b--;
					ans_a++, ans_b++;	
				}else{
					ta += v[a];
					a++;
					ans_a++;
				}
			}
		}

		cout << ans_a << " " << ans_b << endl;
	}
}
