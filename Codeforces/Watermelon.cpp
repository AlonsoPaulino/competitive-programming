#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int a; cin>>a;
    if(a==2)cout<<"NO"<<endl;
    else cout<<((a&1)?"NO":"YES")<<endl;
}
