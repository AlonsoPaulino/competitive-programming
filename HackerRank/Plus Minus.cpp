#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int pos = 0, neg = 0, ze = 0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       arr[arr_i] < 0 ? ++neg : (arr[arr_i] > 0 ? ++pos : ++ze);
    }
    printf("%.6f\n%.6f\n%.6f\n", (double) pos / n, (double) neg / n, (double) ze / n);
    return 0;
}
