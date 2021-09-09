const int N = 27;

struct Node{
    bool word;
    Node *v[N];
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *trie;
    
    Node *initNode(void) {
        Node *x = NULL;
        x = (Node *)malloc(sizeof(Node)); /*Returning a node pointer to the beginning of the block*/
        if (x) {
            x->word = 0;
            for (int i = 0; i < N; ++i) {
                x->v[i] = NULL;
            }
        }
        return x;
    }
    
    WordDictionary() {
        trie = initNode();
    }
    
    void addWord(string word) {
        int n = (int) word.size();
        Node *x = trie;
        for (int i = 0; i < n; ++i) {
            int pos = word[i] - 'a';
            if (!x->v[pos]) {
                x->v[pos] = initNode();
            }
            x = x->v[pos];
        }
        x->word = true;
    }
    
    bool search(string word) {
        return dfs(trie, word, 0, (int) word.size());
    }
    
    bool dfs(Node *node, string &word, int i, int n) {
        if (i == n) {
            return node->word;
        }
        if (word[i] == '.') {
            bool ans = false;
            for (int k = 0; k < N; ++k) {
                if (node->v[k]) {
                    ans = ans || dfs(node->v[k], word, i + 1, n);
                }
            }
            return ans;
        }
        if (!node->v[word[i] - 'a']) {
            return false;
        }
        return dfs(node->v[word[i] - 'a'], word, i + 1, n);
    }
};



// Another solution written on 09/08/2021
class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        bool word;
        unordered_map<char, Node*> ady;
        
        Node(bool w) {
            word = w;
        }
    };
    
    Node* root;
    
    WordDictionary() {
        root = new Node(false);
    }
    
    void addWord(string word) {
        int n = (int) word.size();
        Node* node = root;
        for (int i = 0; i < n; ++i) {
            auto it = node->ady.find(word[i]);
            if (it == node->ady.end()) {
                node->ady[word[i]] = new Node(false);
                node = node->ady[word[i]];
            } else {
                node = it->second;
            }
        }
        node->word = true;
    }
    
    bool search(string word) {
        int n = (int) word.size();
        queue<pair<int, Node*>> q;
        q.push({-1, root});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            Node* node = p.second;
            int next = p.first + 1;
            for (auto v: node->ady) {
                if (word[next] == '.' || v.first == word[next]) {
                    if (next == n - 1 && v.second->word) {
                        return true;
                    }
                    if (next < n - 1) {
                        q.push({next, v.second});    
                    }
                }
            }
        }
        
        return false;
    }
};
