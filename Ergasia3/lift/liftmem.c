#include <stdio.h>
#include <stdlib.h>

int M(int i, int j, int nrid,int dests[], int INF,int **mem);
int fw(int a, int b, int nrid, int dests[]);
int min(int x, int y);

int solve(int nrid ,int nst ,int dests[]) {
    int nfl = 0, min =2137483647 ,INFINITE ,laststop;
    
    /*     nfl is a value used to to store the highest desired floor
    min is a value to start with so it doesn't mess the code
    INFINITE is the value where we will just use as a really high value ,defined by the highest floor to reach
    laststop is a value where we will use to calculate the last elevator stop
    */
   
    for (int i=0; i< nrid; i++) {                     //for loop to find the highest floor a rider needs to go
        if (dests[i] > nfl)
            nfl = dests[i];
        else
            continue;
    }
    INFINITE = 4*nfl;
    
    int **mem;                                                    //create a 2d array to store the cost values
    mem = malloc((nst+1)* sizeof(int*));
    for(int x=0;x < (nst+1);x++) {
        mem[x] = malloc((nfl + 1) * sizeof(int));
    }
    for(int i=0 ;i < (nst +1) ;i++) {                            //we set all the values of the 2d array to -1
        for(int j=0 ;j < (nfl +1) ;j++) {
            mem[i][j] = -1;
        }
    }

    for(int j = 0;j <= nfl;j++) {                                  //we do a for loop to find the minimum cost
        if (min > M(nst,j,nrid,dests,(INFINITE),mem)) {
            min = M(nst,j,nrid,dests,(INFINITE),mem);
            laststop =j;
        }
    }
    if(nst == 0)                                      //if there are no stops ,then there is no elevator stops
        printf("No lift stops\n");
    else {
        printf("Last stop at floor %d\n",laststop);
    }
    
    for(int x=0;x < (nst+1);x++) {                  //here we start to free the ram from the arrays we created
        free(mem[x]);
    }
    free(mem);
    
    return min;
}

int M(int i, int j, int nrid,int dests[], int INFINITE,int **mem) {            //this is the Min main function
    if (mem[i][j] != (-1) )
        return mem[i][j];
    int rec , temp;
    if (i == 0)
        rec = fw(0,INFINITE,nrid,dests);
    else {
        rec = M((i-1) ,0 ,nrid ,dests ,INFINITE ,mem) - fw(0 ,INFINITE ,nrid ,dests) + fw(0 ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
        for (int k = 1; k <= j; k++) {
            temp = M((i-1) ,k ,nrid ,dests ,INFINITE ,mem) - fw(k ,INFINITE ,nrid ,dests) + fw(k ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
            if (temp < rec) {
                rec = temp;
            }
        }
    }
    mem[i][j] = rec;
    return rec;
    
}

int fw(int a, int b, int nrid, int dests[]) {                    //this the floor walking total value function
    int sum = 0;
    for(int i = 0; i <= (nrid -1); i++) {
        if ( (dests[i]<= b) && (dests[i] > a) ) {
            sum += min( (b-dests[i]) , (dests[i]-a) );
        }
    }
    return sum;
}
int min(int x, int y) {                       //this is a function to compare two values and return the lowest
    if (x > y)
        return y;
    else if (y > x)
        return x;
}