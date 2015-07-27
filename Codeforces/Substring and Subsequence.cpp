#include <bits/stdc++.h>
#define MAX 5005
#define mod 1000000007
using namespace std;

int dp[MAX][MAX];
string s, t;

void suma(int &a, int b){
	a += b;
	if(a >= mod) a-= mod;
}

void init(){
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			dp[i][j] = 0;
		}
	}
}

int main(){
	while(cin>>s>>t){
		init();
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < t.size(); j++){
				dp[i+1][j+1] = dp[i+1][j];
				if(s[i] == t[j]) suma(dp[i+1][j+1], dp[i][j] + 1);
			}
		}

		int l = s.size();
		int ans = 0;
		for(int i = 0; i < l; i++) suma(ans, dp[i+1][t.size()]);
		cout<<ans<<endl;
	}
}