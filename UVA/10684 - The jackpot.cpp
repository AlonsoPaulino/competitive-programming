#include <bits/stdc++.h>
#define vi vector<int>
#define sz(x) x.size()
#define DEBUG(x) cout << #x << " -> " << x << endl
#define MAX 10001
using namespace std;

int n, ans;
vi v(MAX);

int kadane() {
	int max_so_far = v[0];
	int current_max = v[0];
	for (int i = 1; i < n; ++i) {
		current_max = max(v[i], current_max + v[i]);
		max_so_far = max(max_so_far, current_max);
	}
	return max_so_far;
}

int main() {
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		ans = kadane();
		if (ans <= 0) {
			cout << "Losing streak." << endl;
		} else {
			cout << "The maximum winning streak is " << ans << "." << endl;
		}
	}
	return 0;
}