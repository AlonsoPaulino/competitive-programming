#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#define N 1000000
using namespace std;
bool v[N];

void criba (){
    memset (v, true, sizeof (v));
    v [0] = false;
    v[1] = false;
 
    for ( int i = 4; i < N; i += 2 )
        v [i] = false;
 
    for ( int i = 3; i * i <= N; i++ ) {
        if ( v [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                v [j] = false;
        }
    }
}

int main(){
    criba();
    int number;
    while(cin>>number){
        int a,b;
        bool flag = false;
        if(number==0)return 0;
        else{
            int pos = 2;
            while(!flag && pos<=number/2){
                if(v[pos] && v[number-pos]){
                    a = pos;
                    b = number-pos;
                    flag = true;
                }else{
                    pos++;
                }
            }
        }
        if(flag)cout<<number<<" = "<<a<<" + "<<b<<endl;
        else cout<<"Goldbach's conjecture is wrong."<<endl;
    }
}