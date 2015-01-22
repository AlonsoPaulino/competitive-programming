#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction (string s1, string s2)
{
    string aux1, aux2;
    aux1 = aux2 = "";
    aux1 = s1 + s2;
    aux2 = s2 + s1;
    bool retorno = false;
    if(aux1>aux2){
        retorno = true;
    }
    return retorno;
}
int main ()
{
    int n;
    while (cin>>n) {
        if(n==0) return 0;
        else{
            vector<string> v;
            while(n--){
                string aux;
                cin>>aux;
                v.push_back(aux);    
                sort (v.begin(),v.end(),myfunction);
            }
            int l = v.size();
            for(int i=0; i<l; i++){
                cout<<v[i];    
            }endl(cout);
        }
    }
}
