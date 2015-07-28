#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int k1, k2, ans;

int gcd(int a, int b){
	return (b == 0)?  a : gcd(b, a%b);
}

int main(){
	while(cin>>k1){
		
		if(k1 == 0) return 0;
		
		set<int> s;
		set<int>::iterator it;

		bool flag = false;
		
		while(cin>>k2){
			if(k2 == 0) break;
			s.insert(k2 - k1);
			if(!flag) ans = (k2 - k1), flag = true;
			
		}

		for(it = s.begin(); it != s.end(); ++it){
			ans = gcd(ans, *it);
		}

		cout<<abs(ans)<<endl;
	}
}