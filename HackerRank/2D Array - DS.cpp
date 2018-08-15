 #include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int n = arr.size();
    int m = 6;
    
    vector<vector<int>> sum;
    
    for (int i = 0; i < n; ++i) {
        vector<int> vj = arr[i];
        vector<int> vsum(6);
        
        vsum[0] = vj[0];
        
        for (int j = 1; j < m; ++j) {
            vsum[j] = vsum[j - 1] + vj[j];
        }
        
        sum.push_back(vsum);
    }
    
    int ans = -100000000;
    
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            ans = max(ans, sum[i][j + 2] - (j > 0 ? sum[i][j - 1] : 0) + arr[i + 1][j + 1] + sum[i + 2][j + 2] - (j > 0 ? sum[i + 2][j - 1] : 0));
        }
    }
    
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
