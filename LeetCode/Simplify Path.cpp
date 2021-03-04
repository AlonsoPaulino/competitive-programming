class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = (int) path.size();
        int i = 0;
        
        while (i < n) {
            if (path[i] == '/') {
                string dir = "";
                ++i; 
                while (i < n && path[i] != '/') {
                    dir += path[i++];
                }
                if (dir == "..") {
                    if (!st.empty()) st.pop();   
                } else if (dir == "." || dir.size() == 0) {
                    continue;
                } else {
                    st.push("/" + dir);
                }
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            string x = st.top(); st.pop();
            ans = x + ans;
        }
        
        if (ans.size() == 0) ans += "/";
        
        return ans;
    }
};
