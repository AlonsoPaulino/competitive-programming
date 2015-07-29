#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int n, aux, ans;
string s;

int gcd(int a, int b){
	return (b == 0)? a : gcd(b, a%b);
}

int main(){
	
	cin >> n;
	string s; 
	getline(cin, s);

	while( n-- ){
		
		ans = 0;
		getline(cin, s);
		istringstream ss(s);
		
		vector<int> v;

		while(ss >> aux) v.push_back(aux);

		int l = v.size();

		for(int i = 0; i < l; ++i){
			for(int j = (i + 1); j < l; ++j){
				int aux_gcd = gcd(v[i], v[j]);
				ans = (aux_gcd > ans)? aux_gcd : ans;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}