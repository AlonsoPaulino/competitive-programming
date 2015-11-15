#include <bits/stdc++.h>
#define AZ 27
#define pb push_back
#define test() cerr << "ozhe khé" << endl;
#define DEBUG(x) cout << #x << " -> " << x << endl;
#define DEBUG2(x,y) cout << #x << " -> " << x << " & " << #y << " -> " << y << endl;
using namespace std;

string s1, s2;
bool idx[AZ];
int tb;

struct node {
	node *x[AZ];
	int bads;
};

struct trie {
	node *root;
};

int charToIndex(char c) {
	return (int) c - (int) 'a';
}

node *initNode() {
	node *n = NULL;
	n = (node *)malloc(sizeof(node));
	if (n) {
		for (int i = 0; i < AZ; ++i) {
			n->x[i] = NULL;
			n->bads = 0;
		}
	}
	return n;
}

void insert(trie *t, string s) {
	int l = s.size();
	node *aux = t->root;
	for (int i = 0; i < l; ++i) {
		int k = charToIndex(s[i]);
		if (!aux->x[k]) {
			aux->x[k] = initNode();
		}
		aux = aux->x[k];
	}
}

void initTrie(trie *t) {
	t->root = initNode();
}

int bfs(trie *t) {
	node *fi = t->root;
	queue<node*> q;
	q.push(fi);
	int ans = 0;
	while (!q.empty()) {
		node *n = q.front();
		q.pop();
		for (int i = 0; i < AZ; ++i) {
			if (n->x[i]) {
				node *aux = n->x[i];
				aux->bads = (!idx[i])? n->bads + 1 : n->bads;
				if (aux->bads <= tb) {
					q.push(aux);
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	while (cin >> s1 >> s2 >> tb) {
		int l1 = s1.size(), l2 = s2.size();
		memset(idx, 0, sizeof(idx));
		for (int i = 0; i < l2; ++i) {
			if (s2[i] == '1') {
				idx[i] = 1;
			}
		}
		trie t; initTrie(&t);
		int sl = l1;
		for (int i = 0; i < l1; ++i) {
			insert(&t, s1.substr(i, sl--));
		}
		cout << bfs(&t) << endl;
	}
}