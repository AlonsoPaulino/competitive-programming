#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

typedef long long ll;
vector<ll> v(MAX);
int n;

int main(){

	while ( cin >> n ){
		for ( int i = 0; i < n; ++i ) cin >> v[i];
		for ( int i = 0; i < n; ++i ){
			if(i > 0 && i < (n - 1)){
				cout << (ll) min(abs(v[i+1] - v[i]), abs(v[i-1] - v[i])) << " ";
				cout << (ll) max(abs(v[n-1] - v[i]), abs(v[0] - v[i])) << endl;
			}else{
				if(i == 0){
					cout << (ll) abs(v[i+1] - v[i]) << " " << (ll) abs(v[n-1] - v[0]) << endl;
				}else{
					cout << (ll) abs(v[n-1] - v[n - 2]) << " " << (ll) abs(v[n - 1] - v[0]) << endl;
				}
			}
		}
	}
}
