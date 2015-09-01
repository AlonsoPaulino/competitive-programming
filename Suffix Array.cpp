#include <bits/stdc++.h>
#define MAX 101
using namespace std;

string s;
int n;

struct suffix{
	int idx;
	int r[2];
};

suffix suf[MAX];

int suffixArray[MAX];

bool cmp(suffix a, suffix b){
	return (a.r[0] == b.r[0])? (a.r[1] < b.r[1]) : (a.r[0] < b.r[0]);
}

void buildSuffixArray(){
	n = s.size();
	for ( int i = 0; i < n; ++i ){
		suf[i].idx = i;
		suf[i].r[0] = s[i] - 'a';
		suf[i].r[1] = ((i + 1) < n)? s[i+1] - 'a' : -1;
	}

	sort(suf, suf + n, cmp);
	int ind[n];

	for (int i = 4; i < 2*n; i = (1 << i)){
		int r = 0;
		int prev_r = suf[0].r[0];
		suf[0].r[0] = r;
		ind[suf[0].idx] = 0;

		for( int j = 1; j < n; ++j){
			if(suf[j].r[0] == prev_r && suf[j].r[1] == suf[j-1].r[1]){
				prev_r = suf[j].r[0];
				suf[j].r[0] = r;
			}else{
				prev_r = suf[j].r[0];
				suf[j].r[0] = ++r;
			}
			ind[suf[j].idx] = j;
		}

		for( int k = 0; k < n; ++k){
			int next_idx = suf[k].idx + i/2;
			suf[k].r[1] = (next_idx < n)?suf[ind[next_idx]].r[0] : -1;
		}

		sort(suf, suf + n, cmp);

		for( int k = 0; k < n; ++k){
			suffixArray[k] = suf[k].idx;
		}
	}
}

int main(){
	while( cin >> s){
		buildSuffixArray();
		for (int i = 0; i < n; i++){
        	for (int j = suffixArray[i]; j < n; ++j){
        		cout << s[j];
        	}
        	endl(cout);
		}
	}
}
