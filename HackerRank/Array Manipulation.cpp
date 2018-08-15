#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void modify(vector<long> &v, int i, long x) {
    while (i < v.size()) {
        v[i] += x;
        i += (i & -i);
    }
}

long read(vector<long> &v, int i) {
    long sum = 0LL;
    while (i > 0) {
        sum += v[i];
        i -= (i & -i);
    }
    return sum;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> bit(n + 5, 0LL);
    
    for (int i = 0; i < queries.size(); ++i) {
        int l = queries[i][0], r = queries[i][1];
        long x = (long) queries[i][2];
        
        modify(bit, l, x);
        modify(bit, r + 1, -x);
    }
    
    long ans = 0LL;
    
    for (int i = 1; i <= n; ++i) {
        long x = read(bit, i);
        ans = max(ans, x);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
