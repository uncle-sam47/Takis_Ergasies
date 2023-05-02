#include <stdio.h>
#include <stdlib.h>

int M(int i, int j, int nrid,int dests[], int INF);
int fw(int a, int b, int nrid, int dests[]);
int min(int x, int y);

int solve(int nrid ,int nst ,int dests[]) {
    int nfl = 0 ,min =2137483647 ,INFINITE ,laststop;
    
    /*   nfl is a value used to to store the highest desired floor
    min is a value to start with so it doesn't mess the code
    INFINITE is the value where we will just use as a really high value ,defined by the highest floor to reach
    laststop is a value where we will use to calculate the last elevator stop
    */

    for(int i=0; i< nrid; i++) { 
        if (dests[i] > nfl)                           //for loop to find the highest floor a rider needs to go
            nfl = dests[i];
        else
            continue;
    }
    INFINITE = 4*nfl;
    for(int j = 0;j <= nfl;j++) {
        if (min > M(nst,j,nrid,dests,(INFINITE))) {
            min = M(nst,j,nrid,dests,(INFINITE));
            laststop =j;
        }
    }
    
    if(nst == 0)                                      //if there are no stops ,then there is no elevator stops
        printf("No lift stops\n");
    else {
        printf("Last stop at floor %d\n",laststop);
    }

    return min;
}

int M(int i, int j, int nrid,int dests[], int INFINITE) {
    int res , temp;
    if (i == 0)
        res = fw(0,INFINITE,nrid,dests);
    
    else {
        res = M((i-1) ,0 ,nrid ,dests ,INFINITE) - fw(0 ,INFINITE ,nrid ,dests) + fw(0 ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
        
        for(int k = 1; k <= j; k++) {
            temp = M((i-1) ,k ,nrid ,dests ,INFINITE) - fw(k ,INFINITE ,nrid ,dests) + fw(k ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
            if (temp < res) {
                res = temp;
            }
        }
    }
    return res;
    
}

int fw(int a, int b, int nrid, int dests[]) {
    int s = 0;
    for(int i = 0; i <= (nrid -1); i++) {
        if ( (dests[i]<= b) && (dests[i] > a) ) {
            s += min( (b-dests[i]) , (dests[i]-a) );

        }
    }
    return s;
}
int min(int x ,int y) {
    if (x > y)
        return y;
    else if (y > x)
        return x;
}