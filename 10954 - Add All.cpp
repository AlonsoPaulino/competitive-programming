#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0)return 0;
        vector<long long> v;
        while(n--){
            long long a;
            cin>>a;
            v.push_back(a);
        }    
        sort(v.begin(),v.end());
        int l = v.size();
        long long suma = v[0] + v[1];
        v[1] = suma;
        vector<long long> sumas;
        sumas.push_back(v[1]);
        for(int i=1; i<l-1; i++){
                sort(v.begin()+i,v.end());   
                v[i+1] += v[i];
                sumas.push_back(v[i+1]);
        }
        int l2 = sumas.size();
        long long total = 0;
        for(int i=0; i<l2; i++){
            total+=sumas[i];    
        }cout<<total<<endl;
    }
}
