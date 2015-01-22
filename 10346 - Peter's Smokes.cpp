#include <iostream>
using namespace std;
main(){
    int n,k;
    while(cin>>n>>k){
        int r = n;
        int acum = n;
        while(r>=k){
            n = r/k;
            r = n+(r%k);
            acum+=n;
        }
        cout<<acum<<endl;
    }    
}

