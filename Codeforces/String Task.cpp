#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool v[58];

void init(){
    for(int i = 0; i < 54; ++i) v[i] = false;
    v['A'-'A'] = true;
    v['O'-'A'] = true;
    v['Y'-'A'] = true;
    v['E'-'A'] = true;
    v['U'-'A'] = true;
    v['I'-'A'] = true;
    v['a'-'A'] = true;
    v['o'-'A'] = true;
    v['y'-'A'] = true;
    v['e'-'A'] = true;
    v['u'-'A'] = true;
    v['i'-'A'] = true;
}

int main(){
    init();
    string s; cin>>s;
    string ans = "";
    int l = s.size();
    for(int  i = 0; i < l ; ++i){
        if(!v[s[i]-'A']){
            ans+='.';
            ans+=(s[i]>='A' && s[i]<='Z')?(s[i]+32):s[i];
        }
    }
    cout<<ans<<endl;
}
