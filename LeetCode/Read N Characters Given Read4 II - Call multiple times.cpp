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


// Another solution written on 01/21/2022
class Solution {
public:
    
    int p = 0, sz = 0;
    char *buf4 = new char[4];
    
    int read(char *buf, int n) {
        int cnt = n;
        int x = 0;
        while (p < sz && cnt > 0) {
            buf[x++] = buf4[p++];
            cnt = cnt - 1;
        }
        while (cnt > 0) {
            sz = read4(buf4);
            if (sz == 0) {
                break;
            }
            for (int i = 0; i < sz && cnt > 0; ++i) {
                buf[x++] = buf4[i];
                cnt = cnt - 1;
                p = i + 1;
            }
        }
        return n - cnt;
    }
};
