#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define sz(x) x.size()
using namespace std;


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s = "";
        for (int j = 1; j < n - i; ++j) {
            s += " ";
        }
        for (int j = sz(s); j < n; ++j) {
            s += "#";
        }
        cout << s << "\n";
    }
    return 0;
}
