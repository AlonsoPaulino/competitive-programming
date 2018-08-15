#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    ull sum = 0LL;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       sum += (ull)arr[arr_i];
    }
    cout << sum << "\n";
    return 0;
}
