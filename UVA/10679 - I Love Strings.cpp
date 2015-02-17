#include <iostream>
using namespace std;

bool subcadena(string a, string b){
    if(a.size() > b.size()){
        return false;    
    }else{
        int l = b.size();
        int longAux = a.size();
        int i = 0;
        int resta = l-i;
        while(resta>=longAux){
            if(b[i] == a[0]){
                if(longAux == 1) return true; 
                int inicio = i+1; 
                int temp = inicio;
                int final = i + longAux - 1;
                int pos1 = 1;
                int pos2 = longAux-1; 
                bool val = true;
                int valor; 
                if(longAux&1) valor = (longAux/2) + 1;
                else valor = longAux/2;
                while(inicio<=(temp-1+valor)){
                    if(b[inicio] == a[pos1] && b[final-pos1+1]== a[pos2]){
                        pos1++;
                        pos2--;
                        inicio++;
                    }else{
                        val = false;
                        inicio = temp+valor;
                        i = final-1;
                    }
                }                   
                if(val)return true;
            }
            i++; 
            resta = l-i;
        }
        return false; 
    }
}

main(){
    int k;
    cin>>k;
    while(k--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        while(q--){
            string aux;
            cin>>aux;
            if(subcadena(aux,s)){
                cout<<"y"<<endl;
            }else{
                cout<<"n"<<endl;
            }
        }   
    }
}
