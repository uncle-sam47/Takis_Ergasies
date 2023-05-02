#include <stdio.h>
#include <stdlib.h>
#include "liftrec.h"                                                            //Recursive method
#include "liftmem.h"                                          //Recursive with Memorization method
#include "liftdp.h"                                    //iterative with Dynamic programming method

int main () {
    int nrid , nst ;             // nrid is the number of riders ,while nst is the number of stops
    scanf("%d %d",&nrid,&nst);          //Start by getting as input the number of riders and stops
    int *dests;
    dests = malloc(nrid* sizeof(int));                 //Create a table using the number of riders
    for (int i=0; i< nrid; i++) {
        scanf("%d",&dests[i]);   //Create a for loop to store the value of the riders destinations
    }
   
    
    int /*nfl = 0,*/ *pdest;           //nfl is a value used to to store the highest desired floor
    pdest = &dests[0];      //*pdest is a pointer to the beginning of the table we created earlier
  
    int MinCost = 0;
    MinCost = solve(nrid,nst,pdest);
    printf("Cost is: %d\n",MinCost);
    
    free (dests);                                   //here we free the array of dests from the Ram
    
    return 0;                                                              //Here ends the program
}