#include <stdio.h>
 
bool a [1000003];
 
void prime (){
    for ( int i = 0; i < 1000003; i++ )
        a [i] = true;
 
    for ( int i = 2; i < 1002; i++ ) {
        for ( int j = i * i; j < 1000003; j += i )
            a [j] = false;
    }
 
    a [0] = a [1] = false;
}
 
int main (){
    prime ();
    int n;
    while ( scanf ("%d", &n) && n ) {
        int last;
        if ( n % 2 == 0 ) last = n - 1;
        else last = n - 2;
        if ( a [n - 2] ) {
            printf ("%d:\n%d+%d\n", n, 2, n - 2);
            continue;
        }
 
        bool flag = true;
        while ( n - last <= last ) {
            if ( a [last] && a [n - last] ) {
                printf ("%d:\n%d+%d\n", n, n - last, last);
                flag = false;
                break;
            }
            last -= 2;
        }
 
        if ( flag )
            printf ("%d:\nNO WAY!\n", n);
    }
 
    return 0;
}
