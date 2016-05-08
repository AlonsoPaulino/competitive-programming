#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int t, s, q;

int main() {
  while (cin >> t >> s >> q) {
    int ans = 0;
    while (s < t) {
      s *= q;
      ++ans;
    }
    cout << ans << endl;      
  }    
}