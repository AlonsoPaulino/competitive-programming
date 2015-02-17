#include <iostream>
using namespace std;

bool isPrime(int x){
   if(x<2)return true;
   if(x == 2)return true;
   if(!(x&1))return false;
   for(int  i = 3; i*i<=x;i=i+2){
      if(x%i == 0)return false;      
   }
   return true;
}

int main(){
	string s;
	while(cin>>s){
		int acum = 0;
		for(int i=0; i<s.size(); i++){
			int k = s[i];
			if(s[i]>='a'&& s[i]<='z'){
				acum+=k-96;
			}else 
				acum+=k-38;
		}
		cout<<acum<<endl;
		if(isPrime(acum))cout<<"It is a prime word."<<endl;
		else cout<<"It is not a prime word."<<endl;
	}
}