#include <bits/stdc++.h>
using namespace std;

int l, i;
string s, aux;
vector<string> ans;

bool check(int pos){
	if((pos + 1) < l && (pos + 2) < l){
		return (s[pos] == 'W' && s[pos + 1] == 'U' && s[pos + 2] == 'B');
	}

	return false;
}

int main(){
	while (cin >> s) {
		l = s.size(), i = 0;
		aux = "";
		ans.clear();

		while (i < l) {
			if(check(i)){
				if(aux != ""){
					ans.push_back(aux);
					aux = "";
				}

				i += 3;
			
			}else{

				aux += s[i];
				i++;
			}
		}

		if(aux != "") ans.push_back(aux);

		for (int i = 0; i < ans.size(); ++i){
			if (i != 0) cout << " ";
			cout << ans[i];
		}

		endl(cout);
	}
}