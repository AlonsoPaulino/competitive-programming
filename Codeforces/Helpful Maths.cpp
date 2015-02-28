#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAX 105
using namespace std;

int main(){
    string s; vector<int> v(MAX);
    while(cin>>s){
        int l = s.size(); int n = (l/2)+1;
        for(int  i = 0; i < l; i+=2){
            v[i/2] = (s[i] - '0');
        }
        sort(v.begin(), v.begin()+n);
        for(int i = 0; i < n; ++i){
            cout<<v[i];
            if(i != (n-1))cout<<"+";
        }
        endl(cout);
    }
}
