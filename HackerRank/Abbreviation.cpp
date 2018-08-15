#include <bits/stdc++.h>

using namespace std;

bool same(char a, char b) {
    return a == b || toupper(a) == b;
}

bool isLowerCase(char c) {
    return (int) c & 32;
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int la = a.size();
    int lb = b.size();
    
    bool dp[lb + 1][la];
    
    for (int i = 0; i < lb + 1; ++i)
        for (int j = 0; j < la; ++j) dp[i][j] = 0;
    
    dp[0][0] = isLowerCase(a[0]);
    dp[1][0] = same(a[0], b[0]);
    
    for (int i = 0; i < lb + 1; ++i) {
        for (int j = 0; j < la; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 1 && j == 0) continue;
            dp[i][j] = (j >= i - 1) && (i > 0 && dp[i - 1][j - 1] && same(a[j], b[i - 1])) || (isLowerCase(a[j]) && dp[i][j - 1]);
        }
    }
    
    return dp[lb][la - 1] ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
