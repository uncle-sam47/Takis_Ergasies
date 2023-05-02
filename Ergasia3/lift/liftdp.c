#include <stdio.h>
#include <stdlib.h>

int fw(int a, int b, int nrid, int dests[]);
int min(int x, int y);

int solve(int nrid ,int nst ,int dests[]) {
    int nfl = 0 ,min =2137483647 ,INFINITE ,laststop ,temp;
    
    /*     nfl is a value used to to store the highest desired floor
    min is a value to start with so it doesn't mess the code
    INFINITE is the value where we will just use as a really high value ,defined by the highest floor to reach
    laststop is a value where we will use to calculate the last elevator stop
    */

    for (int i=0; i< nrid; i++) { 
        if (dests[i] > nfl)                           //for loop to find the highest floor a rider needs to go
            nfl = dests[i];
        else
            continue;
    }
    INFINITE = 4*nfl;

    int *stoporder;                                                 //create a 2d table to save the stop order
    stoporder = malloc(nst*sizeof(int));

    int **stops;                                                         //create a 2d table to save the stops
    stops = malloc((nst+1) * sizeof(int*));
    for (int i = 0 ;i < (nst + 1) ;i++) {
        stops[i] = malloc((nfl+1)*sizeof(int));
    }

    int **dp;                                                            //create a 2d table to save the costs
    dp = malloc((nst+1)* sizeof(int*));
    for(int x=0;x < (nst+1);x++) {
        dp[x] = malloc((nfl + 1) * sizeof(int));
    }
    for (int j = 0 ;j < (nfl + 1) ;j++) {                //create a for loop for the first line of stops array
        dp[0][j] = fw(0 ,INFINITE ,nrid ,dests);
        stops[0][j] = 0;
    }

    for (int i = 1; i < (nst + 1); i++) {                                       //i is for the number of stops
        for (int j = 0; j < (nfl +1) ;j++) {                                    //j is for the number of floor
            dp[i][j] = dp[(i-1)][0] - fw(0 ,INFINITE ,nrid ,dests) + fw(0 ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
            stops[i][j]=0;
            for(int k = 1; k <= j; k++) {
                temp = dp[(i-1)][k] - fw(k ,INFINITE ,nrid ,dests) + fw(k ,j ,nrid ,dests) + fw(j ,INFINITE ,nrid ,dests);
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                    stops[i][j]=k;
                }

            }
        }
    }
    for (int i = 0; i < (nst + 1); i++) {                     //here we print the values of the 2d array of dp
        for (int j = 0; j < (nfl +1) ;j++) {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
        
    }

    for(int j = 0;j <= nfl;j++) {
        if (min > dp[nst][j]) {
            min = dp[nst][j];
            laststop = j;
        }
    }
    stoporder[(nst-1)] = laststop;
    for (int i = (nst-2); i >= 0; i--) {              //this is where on the stops 2d array we find the floors
        stoporder[i] = stops[i+2][laststop];
        laststop =stoporder[i];
    }
    
    if(nst == 0)                                      //if there are no stops ,then there is no elevator stops
        printf("No lift stops\n");
    else {
        printf("Lift stops are:");
        for (int i = 0; i < nst; i++) {
            if (stoporder[i] != 0)
                printf(" %d",stoporder[i]);
        }
    }
    printf("\n");
                                       //here is the part where we free the ram from all the arrays we created
    free(stoporder);
    for (int i = 0 ;i < (nst + 1) ;i++) {
        free(dp[i]);
    }
    free(dp);
    for (int i = 0 ;i < (nst + 1) ;i++) {
        free(stops[i]);
    }
    free(stops);
           //here ends the solve function and returns back the value of min which is the last value of MinCost
    return min;
}

int fw(int a, int b, int nrid, int dests[]) {                  //function to calculate the total floors walked
    int sum = 0;
    for(int i = 0; i <= (nrid -1); i++) {
        if ( (dests[i]<= b) && (dests[i] > a) ) {
            sum += min( (b-dests[i]) , (dests[i]-a) );
        }
    }
    return sum;
}
int min(int x, int y) {                             //Function to compare two int values and return the lowest
    if (x > y)
        return y;
    else if (y > x)
        return x;
}