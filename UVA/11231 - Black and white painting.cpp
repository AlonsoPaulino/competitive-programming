#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c)){
        if(n!=0 || m!=0 || c != 0){
            int total = 0;
            bool impar = false;
            if(n&1) impar = true;
            if(c){
                for(int i=n; i>=8; i--){
                    if(impar){
                        if(i&1){
                            if(m-8>=0)
                                total+=((m-8)/2)+1;
                        }else{
                            if(m-9>=0)
                                total+=((m-9)/2)+1;
                        }
                    }else{
                        if(!(i&1)){
                            if(m-8>=0)
                                total+=((m-8)/2)+1;
                        }else{
                            if(m-9>=0)
                                total+=((m-9)/2)+1;    
                        }    
                    }                    
                }    
            }else{
                for(int i=n; i>=8; i--){
                    if(impar){
                        if(i&1){
                            if(m-9>=0)
                                total+=((m-9)/2)+1;    
                        }else{
                            if(m-8>=0)
                                total+=((m-8)/2)+1;    
                        }
                    }else{
                        if(!(i&1)){
                            if(m-9>=0)
                                total+=((m-9)/2)+1;    
                        }else{
                            if(m-8>=0)
                                total+=((m-8)/2)+1;    
                        }    
                    }                    
                }
            }printf("%d\n",total);
        }else return 0;
    }
}
