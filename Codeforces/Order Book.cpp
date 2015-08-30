#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int buy[MAX];
int sell[MAX];
int n, s, pi, qi;
char di;

struct order{
	char d;
	int p;
	int q;
};

bool sortbook(order o1, order o2){
	return o1.p > o2.p;
}

int main(){
	while( cin >> n >> s ){
		memset(buy, 0, sizeof(buy));
		memset(sell, 0, sizeof(sell));
		
		for(int i = 0; i < n; ++i){
			cin >> di >> pi >> qi;
			if ( di == 'B' ){
				buy[pi] += qi;
			}else{
				sell[pi] += qi;
			}
		}

		int cont = 0;

		vector<order> ans;

		for(int i = 0; (i < MAX) && (cont < s); ++i){
			if(sell[i] > 0){
				order o;
				o.d = 'S' , o.p = i , o.q = sell[i];
				ans.push_back(o);
				cont++;
			}
		}

		cont = 0;

		for(int i = (MAX - 1); (i >= 0) && (cont < s); --i){
			if(buy[i] > 0){
				order o;
				o.d = 'B' , o.p = i , o.q = buy[i];	
				ans.push_back(o);
				cont++;
			}
		}

		sort(ans.begin(), ans.end(), sortbook);

		for(int i = 0; i < ans.size(); ++i){
			order aux = ans[i];
			cout << aux.d << " " << aux.p << " " << aux.q << endl;
		}
	}
}
