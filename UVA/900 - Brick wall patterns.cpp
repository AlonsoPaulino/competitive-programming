#include <iostream>
using namespace std;

int main(){
    
    long long valor;
    while(cin>>valor){
        long long a = 1;
        long long b = 2;
        if(valor==1){
            cout<<a<<endl;    
        }else{
            for(int i=2; i<valor; i++){
                long long aux = b;
                b = a+b;
                a = aux;
            }   
            cout<<b<<endl;
        }
    }    
}
