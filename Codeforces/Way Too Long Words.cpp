#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    int cases; cin>>cases;
    string s;
    while(cases--){
        cin>>s;
        if(s.size() > 10){
            cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
        }else cout<<s<<endl;
    }
}
