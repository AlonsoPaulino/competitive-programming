#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ans = 0;

ll gcd(ll a, ll b){
	return (b == 0)? a : gcd(b, a%b);
}

int main(){
	
	while(cin>>n){
		
		if(n == 0) return 0;
		
		if(n == 1) cout<<"1 1"<<endl;
		
		else{
			
			ans = 0;
			vector<int> v;
			
			v.push_back(1);
			
			for(ll i = 2; (i * i) <= n; ++i) 
				if(n % i == 0){ 
					v.push_back(i);
					if(i != (n/i)) v.push_back(n/i);
				}

			v.push_back(n);

			ll l = v.size();
			
			for(ll i = 0; i < l; ++i){
				for(ll j = (i + 1); j < l; ++j){
					ll lcm = v[i] * (v[j] / gcd(v[i], v[j]));
					if(lcm == n) ans++;
				}
			}

			cout<<n<<" "<<ans + 1<<endl;
		}
	}
}