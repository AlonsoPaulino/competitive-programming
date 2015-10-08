#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

string s, pat;
int p[MAX], t, n, matches;

void KMP_array() {
	p[0] = -1;
	int i = 0, j = -1;
	while (i < n) {
		while (j >= 0 && pat[i] != pat[j]) j = p[j];
		i++, j++;
		p[i] = j;
	}
}

void KMP_match() {
	matches = 0;
	int i = 0, j = 0;
	while (i < 2 * n) {
		if (s[i] == pat[j] || j < 0) {
			i++, j++;
			if (j == n) {
				matches++, j = p[j];
			} 
		} else {
			if (j >= 0) j = p[j];
		}
	}
}

void rev() {
	pat = "";
	for (int i = (n - 1); i >= 0; i--) pat += s[i];
}

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		rev(), s += s;
		KMP_array();
		KMP_match();
		if (matches == 0) cout << "simple";
		else if (matches == 2) cout << "palindrome";
		else if (matches >= 3 || matches == 1) cout << "alindrome";
		cout << endl;
	}
	return 0;
}