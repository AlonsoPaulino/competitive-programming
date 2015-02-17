#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <iterator>

using namespace std;
map<char,string > m;

void init(){
	m['F'] = "1111";
	m['E'] = "1110";
	m['D'] = "1101";
	m['C'] = "1100";
	m['B'] = "1011";
	m['A'] = "1010";
	m['9'] = "1001";
	m['8'] = "1000";
	m['7'] = "0111";
	m['6'] = "0110";
	m['5'] = "0101";
	m['4'] = "0100";
	m['3'] = "0011";
	m['2'] = "0010";
	m['1'] = "0001";
	m['0'] = "0000";
}

int binary_to_dec(string b){
	int num = 0; int pos_ini = 0;
	int cant_0 = 13 - b.size();
	for(int i=0; i<cant_0; i++)cout<<"0";
	for(int i=b.size()-1; i>=0; i--){
		cout<<b[pos_ini];
		if(b[i]=='1')num+=1<<pos_ini;
		pos_ini++;
	}	
	return num;
}

int num_dec(string a){
	int pos = a.size()-1;
	string num_binary = "";
	while(pos>=0){
		string binary = m[a[pos]];
		string temp = num_binary;
		num_binary = binary + temp;
		pos--;
	}
	return binary_to_dec(num_binary);
}

int main(){
	init();
	int T; cin>>T;
	while(T--){
		string a,b; char op;
		cin>>a>>op>>b;
		int num_dec_a = num_dec(a);
		cout<<" "<<op<<" ";
		int num_dec_b = num_dec(b);
		cout<<" = ";
		if(op=='+')cout<<num_dec_a+num_dec_b<<endl;
		else cout<<num_dec_a-num_dec_b<<endl;		 
	}
}
