#include <bits/stdc++.h>
using namespace std;

int n, ans, numdig;
int dp [9];
int v[] = {1 , 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1000000000};

bool check(int num){
	while ( num > 0 ) {
		int d = num % 10;
		num /= 10;
		if ( d != 1 && d != 0 ) return false;
	}
	return true;
}

int numDigits(int num){
	int ret = 0;
	while ( num > 0){
		num /= 10;
		ret++;
	}
	return ret;
}

void init(){
	dp[0] = (1 << 0);
	for (int i = 1; i < 9; ++i){
		dp[i] = dp[i-1] + (1 << i);
	}
}

int main(){
	init();
	while ( cin >> n ){
		ans = 0;
		numdig = numDigits(n);
		if(numdig == 1){
			ans = 1;
		}else{
			ans += dp[numdig - 2];
			int ls = min(n, v[numdig - 1]);
			for (int i = pow(10, (numdig - 1)); i <= ls; i++){
				if(check(i)) ans++;
			}

		}

		cout << ans << endl;
	}
}