#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');
    int s = (time[6] - '0') * 10 + (time[7] - '0');
    char x = time[8];
    int hh, mm = m, ss = s;
    if (x == 'A') {
        hh = h;
        if (hh == 12) {
            hh = 0;
        }
    } else {
        hh = h + 12;
        if (hh == 24) {
            hh = 12;
        }
    }
    if (hh < 10) {
        cout << "0" << hh << ":";
    } else {
        cout << hh << ":";
    }
    if (mm < 10) {
        cout << "0" << mm << ":";
    } else {
        cout << mm << ":";
    }
    if (ss < 10) {
        cout << "0" << ss << "\n";
    } else {
        cout << ss << "\n";
    }
    
    return 0;
}
