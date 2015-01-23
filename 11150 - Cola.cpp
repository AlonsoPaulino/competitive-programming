#include <iostream>

using namespace std;

int count_cola(int n) {
        int result = 0;
        while( n >= 3 ) {
                result += n - n%3;
                n = n/3 + n%3;
        }
        if(n==2) return result + n + 1;
        return result + n;
}

int main()
{
        int n;
        while(cin>>n) { 
                cout << count_cola(n) << endl;
        }
        return 0;
}