#include <bits/stdc++.h>
using namespace std;

string s;

bool yes(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'A' || c== 'E' || c== 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main(){
	getline(cin, s);
	int n = s.size() - 2;
	while (s[n] == ' ') n--;
	if (yes(s[n])) cout << "YES";
	else cout << "NO";
	endl(cout);
}
