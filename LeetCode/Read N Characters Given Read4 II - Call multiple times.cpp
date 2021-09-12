/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int bufsz = 0, pos = 0;
    char *tmp = new char[4];
    
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (pos == bufsz) {
                pos = 0;
                bufsz = read4(tmp);
                if (bufsz == 0) break;
            }
            buf[i++] = tmp[pos++];
        }
        return i;
    }
};
