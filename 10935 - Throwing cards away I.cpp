#include <cstdio>
#include <deque>
using namespace std;

int main(){
    deque<int> DQ;
    int n, i;
    while (scanf("%d", &n) && n){
        if (n == 1) puts("Discarded cards:\nRemaining card: 1");
        else{
            for (i = 1; i <= n; i++) DQ.push_back(i);
            printf("Discarded cards: %d", DQ.front());
            DQ.pop_front();
            DQ.push_back(DQ.front());
            DQ.pop_front();
            while (DQ.size() != 1){
                printf(", %d", DQ.front());
                DQ.pop_front();
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            printf("\nRemaining card: %d\n", DQ.front());
            DQ.clear();
        }
    }
    return 0;
}