class Trie {
    struct node{
        bool word;
        node *x[27];
    };
    
    int cnt;
    node *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        cnt = 0;
        root = createNode();
    }
    
    /** Create node */
    node *createNode() {
        node *nd = (node *) malloc(sizeof(node));
        if (nd) {
            nd->word = 0;
            for (int i = 0; i < 27; ++i) nd->x[i] = NULL;
        }
        return nd;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size(); cnt++;
        node *nd = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (!nd->x[idx]) {
                nd->x[idx] = createNode();
            }
            nd = nd->x[idx];
        }
        nd->word = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        node *nd = root;
        for (int i = 0; i < n; ++i) {
            int idx = word[i] - 'a';
            if (!nd->x[idx]) {
                return 0;
            }
            nd = nd->x[idx];
        }
        return (0 != nd && nd->word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        node *nd = root;
        for (int i = 0; i < n; ++i) {
            int idx = prefix[i] - 'a';
            if (!nd->x[idx]) {
                return 0;
            }
            nd = nd->x[idx];
        }
        return (0 != nd);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */