#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int toInt(char c){
    return ((c >= 'a' && c <= 'z')?(c - 'a'):(c - 'A'));
}

int compare(char c1, char c2){
    int v1 = toInt(c1), v2 = toInt(c2);
    if(v1 > v2) return 1;
    else if(v1 == v2) return 0;
    else if(v1 < v2) return -1;
}

int main(){
    string a, b; cin>>a>>b;
    int l = a.size();
    for(int  i = 0; i < l ; ++i){
        int ans = compare(a[i], b[i]);
        if(ans != 0){
            i = l;
            cout<<ans<<endl;
        }else{
            if(i == (l-1)) cout<<ans<<endl;
        }
    }
}
