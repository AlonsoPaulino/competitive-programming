#include <bits/stdc++.h>
#define DEBUG(x) cout<<#x<<"->"<<x<<endl;
#define sz(x) x.size()
using namespace std;

string s, aux1, aux2, ans;
int l;

bool isNumber(char c) {
	return c != ' ' && c!= '.' && c != ',';
}

int main() {
	getline(cin, s);
	l = sz(s);
	aux1 = aux2 = ans = "";
	int i = 0;
	while (i < l) {
		aux1 += s[i];
		if (s[i] == ' ') {
			while (s[i+1] == ' ') ++i;
		}
		++i;
	}
	i = 0, l = sz(aux1);
	while (i < l) {
		if (isNumber(aux1[i])) {
			aux2 += aux1[i];
			if (aux1[i+1] == ' ') {
				++i;
				while (i < l && aux1[i] == ' ') ++i;
				if (isNumber(aux1[i])) {
					aux2 += " ";
				}
			} else {
				++i;
			}
		} else {
			if (aux1[i] != ' ') {
				aux2 += aux1[i];
			}
			++i;
		}
	}
	i = 0, l = sz(aux2);
	int j = -1;
	while (i < l) {
		if (aux2[i] == ',') {
			if (i != l-1) {
				ans += ", ";
				++i;
				j += 2;
			} else {
				ans += ",";
				++i;
				++j;
			}
		} else if (aux2[i] == '.') {
			if (i > 0) {
				if (ans[j] != ' ') {
					ans += " ...";
					i += 3;
					j += 4;
				} else {
					ans += "...";
					i += 3;
					j += 3;
				}
			} else {
				ans += "...";
				i += 3;
				j += 3;
			}
		} else {
			ans += aux2[i];
			++i;
			++j;
		}
	}
	cout << ans << endl;
}