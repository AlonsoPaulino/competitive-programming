class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, int> dic;
        int n = (int) wordList.size();
        int target = -1;
        for (int i = 0; i < n; ++i) {
            dic[wordList[i]] = i;
            if (wordList[i] == endWord) {
                target = i;
            }
        }
        if (target == -1) {
            return 0;
        }
        vector<vector<int>> g(n + 5);
        for (int i = 0; i < n; ++i) {
            string s = wordList[i];
            for (int j = 0; j < s.size(); ++j) {
                char c = s[j];
                for (int k = 0; k < 27; ++k) {
                    char y = 'a' + k;
                    if (c != y) {
                        s[j] = y;
                        auto f = dic.find(s);
                        if (f != dic.end() && f->second != i) {
                            g[i].push_back(f->second);
                            g[f->second].push_back(i);
                        }
                    }
                }
                s[j] = c;
            }
        }
        
        // Just to show the path, not needed for the problem at all
        // ********************************************************
        map<pair<int, int>, int> path;
        // ********************************************************
        
        vector<bool> visited(n + 5, false);
        
        queue<pair<int, int>> q;
        q.push({n - 1, 1});
        visited[n - 1] = true;
        path[{n - 1, 1}] = -1;
        
        while (!q.empty()) {
            
            auto u = q.front(); q.pop();
            if (u.first == target) {
                // Small variation showing the path
                // ************************************
                int x = u.first, y = u.second;
                int p = path[{x, y}];
                
                vector<string> vs;
                
                while (p != -1) {
                    vs.push_back(wordList[x]);
                    x = p, y = y - 1;
                    p = path[{x, y}];
                }
                
                vs.push_back(wordList[x]);
                for (int i = u.second - 1; i >= 0; --i) {
                    cout << vs[i] << " ";
                }
                endl(cout);
                // ************************************
                // END small variation showing the path
                
                return u.second;
            }
            auto ady = g[u.first];
            for (auto v: ady) {
                if (!visited[v]) {
                    q.push({v, u.second + 1});
                    path[{v, u.second + 1}] = u.first;
                    visited[v] = true;
                }
            }
        }
        
        return 0;
    }
};
