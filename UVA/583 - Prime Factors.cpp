#include <bits/stdc++.h>
#define MAX 10000007
using namespace std;

typedef long long ll;

bitset<MAX + 1> bs;
vector<ll> primes;
ll n;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= MAX; ++i){
		if(bs[i]){
			primes.push_back(i);
			for(ll j = i*i; j<= MAX; j+=i){
				bs[j] = 0;
			}
		}
	}
}

vector<ll> getFactors(ll num){
	vector<ll> ans;
	ll i = 0, p = primes[i];
	while(p*p <= num){
		while(num % p == 0){
			ans.push_back(p);
			num /= p;
		}
		p = primes[++i];
	}
	if(num != 1) ans.push_back(num);
	return ans;
}

int main(){

	sieve();

	while(cin >> n){

		if(n == 0) break;

		vector<ll> factors = getFactors(abs(n));

		cout<<n<<" = ";
		if( n < 0 ) cout<<"-1 x ";
		int l = factors.size();
		
		for(int i = 0; i < l; ++i){
			cout<<factors[i];
			if(i < (l-1)) cout<<" x ";
		}

		cout<<endl;
	}

	return 0;
}
