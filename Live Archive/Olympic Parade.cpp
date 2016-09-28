#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, c, ans;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        map<ll, ll> m;
        map<ll, ll>::iterator it;
        ans = 0ll;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            ++m[c];
        }
        it = m.begin();
        while (it != m.end()) {
            if (it->second % k != 0) {
                ans = it->first;
                break;
            }
            ++it;
        }
        cout << ans << "\n";
    }
}