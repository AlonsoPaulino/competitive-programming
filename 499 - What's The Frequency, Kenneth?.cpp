#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

bool my_sort(pair<char, int> p1, pair<char , int> p2){
	return (p1.second == p2.second)?(p1.first < p2.first):(p1.second > p2.second);
}

int main(){
	string s;
	while(getline(cin,s)){
		int n = s.size();
		vector< pair<char,int> > p;
		vector<bool> v(n);
		for(int i=0; i<n; ++i){ 
			v[i] = ((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122))?true:false;
		}
		for(int i=0 ; i<n ; ++i){
			if(v[i]){
				char c = s[i];
				pair<char, int> aux;
				aux.first = c;
				aux.second = 1;
				v[i] = false;
				for(int j = i+1 ; j<n ; ++j){
					if(v[j]){
						if(c == s[j]){
							v[j] = false;
							aux.second = aux.second + 1;
						}
					}
				}
				p.push_back(aux);
			}
		}
		sort(p.begin(),p.end(), my_sort);
		int max = p[0].second;
		cout<<p[0].first;
		int i = 1;
		while(p[i].second == max && i<p.size()){
			cout<<p[i].first;
			i++;
		}
		cout<<" "<<max<<endl;
	}
}