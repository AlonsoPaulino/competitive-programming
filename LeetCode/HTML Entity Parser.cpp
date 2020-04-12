class Solution {
public:
    static void replaceAll(std::string& str, const std::string& from, const std::string& to) {
        if(from.empty())
            return;
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    }
    
    string entityParser(string text) {
        replaceAll(text, "&quot;", "\"");
        replaceAll(text, "&apos;", "'");
        replaceAll(text, "&amp;", "&");
        replaceAll(text, "&gt;", ">");
        replaceAll(text, "&lt;", "<");
        replaceAll(text, "&frasl;", "/");
        return text;
    }
};