#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

bool ordered(vector<int> v){
	int n = v.size();
	int i = 0;
	bool ac = false, dec = false; (v[i+1]>v[i])?ac=true:dec=true;
	i++;
	while(i < (n -1)){
		if(ac){
			if(v[i+1]<v[i])return false;
		}else if(dec){
			if(v[i+1]>v[i])return false;
		}
		i++;
	}
	return true;
}

int main(){
	int t; cin>>t;
	bool first = true;
	while(t--){
		vector<int> v(10);
		for(int i=0; i<10; ++i){
			cin>>v[i];
		}
		if(first){
			cout<<"Lumberjacks:"<<endl;
			first = false;
		}
		cout<<(ordered(v)?"Ordered":"Unordered")<<endl;	
	}
}
