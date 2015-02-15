#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int v[5005];
int v_count[5005];
string vs[5005];
int c, r;


int find(int n){
	return (n == v[n])? n : v[n] = find(v[n]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

int search_pos(string s){
	for(int i = 0; i < c; ++i){
		if(s.compare(vs[i]) == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	while(cin>>c>>r){
		if((c == 0) && (r == 0))return 0;
		for(int i = 0; i < c; ++i) v[i] = i, v_count[i] = 0, cin>>vs[i];
		for(int i = 0; i < r; ++i){
			string s1, s2; cin>>s1>>s2;
			Union(search_pos(s1), search_pos(s2));
		}
		for(int i = 0; i < c; ++i) v_count[find(i)]++;
		int ans = v_count[0];
		for(int i = 1; i < c; ++i) ans = (v_count[i]>ans)?v_count[i]:ans;
		cout<<ans<<endl;	
	}
}
