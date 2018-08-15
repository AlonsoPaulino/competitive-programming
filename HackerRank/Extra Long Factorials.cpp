#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
using namespace std;

string multiply(string a, string b) {
    string result = "";
    result.resize(sz(a) + sz(b), '0');
    int x, s, r, carry;
    for (int i = sz(a) - 1; i >= 0; --i) {
        carry = 0;
        x = a[i] - '0';
        for (int j = sz(b) - 1; j >= 0; --j) {
            s = x * (b[j] - '0') + (result[j + i + 1] - '0') + carry;
            r = s % 10;
            carry = (s - r) / 10;
            result[i + j + 1] = (char) (r + '0');
        }
        result[i] = (char) (carry + '0');
    }
    if (result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

string toString(int x) {
    string result = "";
    while (x > 0) {
        result += ((x % 10) + '0');
        x /= 10;
    }
    if (result == "") {
        return "0";
    }
    reverse(all(result));
    return result;
}

int main(){
    int n;
    cin >> n;
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        string factor = toString(i);
        result = multiply(result, factor);
    }
    cout << result << "\n";
}
