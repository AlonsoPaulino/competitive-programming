#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

string suma(string a, string b){
	int l  = 1+(a.size()>b.size()?a.size():b.size());
	string c(l, '0');
	a = string(l - a.size(), '0') + a;
	b = string(l - b.size(), '0') + b;
	int ac = 0, sum = 0;
	for(int i=l-1; i>=0; i--){
		sum = a[i] + b[i] - '0' - '0' + ac;
		c[i] = (sum%10)+'0';
		ac = sum/10;
	}
	while(c.size()>0 && c[0]=='0'){
		c.erase(c.begin());
	}return c;
}

int main(){
	string s;
	string result = "0";
	while(cin>>s){
		if(s.size()==1 && s[0]=='0')break;
		else{
			result = suma(result,s);
		}
	}
	cout<<result<<endl;
	return 0;
}