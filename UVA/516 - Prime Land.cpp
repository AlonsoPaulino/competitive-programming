#include <bits/stdc++.h>
#define MAX 32767
using namespace std;

bitset<MAX + 1> bs;
vector<int> primes;

void segmented_sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= MAX; ++i){
		if(bs[i]){
			primes.push_back(i);
			for(long long j = i*i ; j <= MAX; j += i) bs[j] = 0;
		}
	}
}

int getNum(vector<int> v){
	int l = v.size();
	int ans = 1;
	for(int i = 0; i < l; i+=2) ans *= pow(v[i], v[i+1]);
	return ans;
}

vector<int> getFacts(int num){	
	
	vector<int> v;
	int i = (primes.size() - 1), p = primes[i];
	
	while(i >= 0){
		if(num % p == 0){
			int power = 1;
			v.push_back(p);
			num /= p;
			while(num % p == 0) power++, num /= p;
			v.push_back(power);
		}
		i -= 1;
		p = primes[i];
	}

	return v;
}

int main(){

	int x;
	segmented_sieve();
	
	while(cin>>x){

		if(x == 0) break;

		string s;
		getline(cin, s);

		vector<int> factors;
		factors.push_back(x);
		istringstream ss(s);
		while(ss >> x) factors.push_back(x);

		int val = getNum(factors);
		vector<int> v = getFacts(val - 1);

		cout<<v[0]<<" "<<v[1];
		for(int i = 2; i < v.size(); i += 2) cout<<" "<<v[i]<<" "<<v[i+1];

		cout<<endl;
	}

	return 0;
}