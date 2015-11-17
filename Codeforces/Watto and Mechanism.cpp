#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " -> " << x <<endl;
#define DEBUG2(x,y) cout << #x << " -> " << x << " & " << #y << " -> " << y << endl;
#define sz(x) x.size()
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ABC 3
using namespace std;

int n, m;
bool ans;
string st, q, q1, q2;

struct node {
	node *x[ABC];
	bool word;
	int diff;
	int h;
};

struct trie {
	node *root;
};

int charToIndex(char c) {
	return (int)c - (int)'a';
}

node *initNode() {
	node *n = NULL;
	n = (node *)malloc(sizeof(node));
	if (n) {
		for (int i = 0; i < ABC; ++i) 
			n->x[i] = NULL, n->word = false, 
			n->diff = 0, n->h = 0;
	}
	return n;
}

void initTrie(trie *t) {
	t->root = initNode();
}

void insert(trie *t, string s) {
	int l = sz(s);
	node *aux = t->root;
	for (int i = 0; i < l; ++i) {
		int k = charToIndex(s[i]);
		if (!aux->x[k]) {
			aux->x[k] = initNode();
			aux->x[k]->h = aux->h + 1;
		}
		aux = aux->x[k];
	}
	aux->word = true;
}

bool bfs(trie *t, string s) {
	int  l = sz(s);
	node *fi = t->root;
	fi->diff = 0;
	queue<node*> q;
	q.push(fi);
	while (!q.empty()) {
		node *aux = q.front();
		q.pop();
		int h = aux->h;
		if (h == l && aux->diff > 0 && aux->word) return true;	
		if (h < l) {
			int k = charToIndex(s[h]);
			for (int i = 0; i < ABC; ++i) {
				if (aux->x[i]) {
					if (i != k) {
						aux->x[i]->diff = aux->diff + 1;
						if (aux->x[i]->diff < 2) {
							q.push(aux->x[i]);
						}
					} else {
						aux->x[i]->diff = aux->diff;
						q.push(aux->x[i]);
					}
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	trie t;
	initTrie(&t);
	while (n--) {
		cin >> st;
		insert(&t, st);
	}
	for (int i = 0; i < m; ++i) {
		cin >> q;
		int l = sz(q);
		cout << ((bfs(&t, q)) ? "YES" : "NO") << endl;
	}
}	