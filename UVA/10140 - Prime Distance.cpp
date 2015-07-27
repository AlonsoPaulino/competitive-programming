#include <iostream>
#include <vector>
#include <bitset>
#define MAX 2147483647
#define MAX_PRIMES 46342
using namespace std;

bitset<MAX_PRIMES+1> bs;
vector<int> primes;

long long l, u, mindiff, maxdiff, c1, c2, d1, d2;
bool flag;

void segmented_sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2 ; i <= MAX_PRIMES ; i++){
		if(bs[i]){
			primes.push_back(i);
			for(long long j = i*i ; j <= MAX_PRIMES; j += i){
				bs[j] = 0;
			}
		}
	}
}

bool isPrime(long long num){
	
	if(num <= MAX_PRIMES) return bs[num];
	if(!(num&1)) return false;
	int i = 0, p = primes[i];
	while((p*p <= num) && (i < primes.size())){
		if((num % p) == 0) return false;
		p = primes[++i];
	}
	return true;
}

int main(){
	
	segmented_sieve();
	
	while(cin>>l>>u){

		mindiff = MAX;
		maxdiff = -1;
		flag = false;

		while(!isPrime(l) && (l <= u)) l++;

		for(long long i = l; i <= u; ++i){
			for(long long j = (i + 1); j <= u; ++j){
				if(isPrime(j)){
					if((j-i) > maxdiff){
						d1 = i;
						d2 = j;
						maxdiff = (j - i);
					}

					if((j-i) < mindiff){
						c1 = i;
						c2 = j;
						mindiff = (j - i);
					}

					flag = true;
					i = j - 1;
					break;
				}
				
			}
		}

		if(flag) cout<<c1<<","<<c2<<" are closest, "<<d1<<","<<d2<<" are most distant."<<endl;
		else cout<<"There are no adjacent primes."<<endl;
	}
}