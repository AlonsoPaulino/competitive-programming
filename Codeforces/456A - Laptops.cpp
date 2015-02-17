#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


bool function(pair<int,int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(){

	int n; cin>>n;	
	vector< pair<int,int> > v(n);

	for(int i=0; i<n; ++i){
		pair<int,int> p;
		cin>>p.first>>p.second;
		v[i] = p;
	}
	
	bool flag = false;
	sort(v.begin(), v.end(), function);

	for(int i=0; i<(n-1) && !flag; ++i){
		if(v[i].first < v[i+1].first && v[i].second > v[i+1].second) flag = true;
	}

	if(flag)cout<<"Happy Alex"<<endl;
	else cout<<"Poor Alex"<<endl;

}