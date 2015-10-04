#include <bits/stdc++.h>
#define MAX 2501
using namespace std;

int n, v[MAX][2];
bool ver[MAX], hor[MAX];
vector<int> ans;

int main() {
	while (cin >> n) {
		n = n*n;
		ans.clear();
		memset(ver, false, sizeof(ver));
		memset(hor, false, sizeof(hor));
		
		for (int i = 0; i < n; ++i) {
			cin >> v[i][0] >> v[i][1];
		}

		for (int i = 0; i < n; ++i) {
			if (!ver[v[i][0]] && !hor[v[i][1]]) {
				ver[v[i][0]] = true;
				hor[v[i][1]] = true;
				ans.push_back(i + 1);
			}
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) {
			if (i == 0) cout << ans[i];
			else cout << " " << ans[i];
		}

		endl(cout);
	}
}