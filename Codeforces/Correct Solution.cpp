#include <bits/stdc++.h>
using namespace std;

int l1, l2, zeros;
string s1, s2;
bool ans;

int main(){
	while ( cin >> s1 ){
		cin >> s2;
		ans = true;
		l1 = s1.size(), l2 = s2.size(), zeros = 0;
		vector<char> v;

		for (int i = 0; i < l1; ++i){
			if ( s1[i] == '0' ){
				zeros++;
			}else{
				v.push_back(s1[i]);
			}
		}

		if(v.size() > 0) sort(v.begin(), v.end());

		if (l2 != l1){
			ans = false;	
		} else{
			if (v.size() > 0){
				if(s2[0] != v[0]) ans = false;
			}else{
				if(s2[0] != '0') ans = false;
			}
			
			for (int i = 1; i <= zeros && i < l2 && ans; ++i){ 
				if (s2[i] != '0') ans = false;
			}

			for (int i = 1; i < v.size() && ans; ++i){
				if (s2[zeros + i] != v[i]) ans = false;
			}
				
		}
		
		cout << ((ans)? "OK" : "WRONG_ANSWER") << endl;;
	}
}
