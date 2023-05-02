#include <stdio.h>
int main()
{
    int n, temp, factor, next, nprime, tempprime, factorprime, countsumprime=0, Mertens=0;
    int tenK = 10 , tenMAXEXP = 10, tempMAXEXP = 1, ZP=0;
    int nZP, DivisorZP, sumdiv, countdef = 0, countabund = 0;
    //Ten to the power of k is tenK
    //here is where Ten to the power of MAXEXP gets calculated ==> tenMAXEXP
    while (tempMAXEXP != MAXEXP) {
        tenMAXEXP  *= 10;
        tempMAXEXP++;
    }
    for (n = 1;n <= tenMAXEXP +9 ; n++) {
        if (n % 4 == 0 ||n % 9 == 0) {
            if(Mertens == 0) {
                ZP++;
            }
            if(n >= tenK -9 && n <= tenK +9 ) {
                printf("M(%d) = %d\n",n,Mertens);
                // here prints the first condition where it's not square-free
            }
            if(n == tenMAXEXP +9){
                break;
            }
            if(n == tenK + 9) {
                printf("..........\n");
                tenK *= 10;
            }
            continue;
        }
        temp = n;
        if (temp % 2 == 0) {
            temp /= 2;
        }
        if (temp % 3 == 0) {
            temp /= 3;
        }
        factor = 5;
        next = 0;
        while (factor * factor <= temp) {
            if (temp % factor == 0) {
                temp /= factor;
                if (temp % factor == 0){
                    next = 1;
                    if(Mertens == 0) {
                        ZP++;
                    }
                    if(n >= tenK -9 && n <= tenK +9 ){
                        printf("M(%d) = %d\n",n,Mertens); 
                        // here prints the second condition where it's still not square-free
                    }
                    if(n == tenMAXEXP +9){
                        break;
                    }
                    if(n == tenK + 9){
                        printf("..........\n");
                        tenK *= 10;
                    }
                    break;
                }
            }
            if (factor % 6 == 5) {
                factor += 2;
            }
            else {
                factor += 4;
            }
        }
        if (next == 0) {   
            // if next = 0 then number is square-free
            nprime = n;
            tempprime = nprime;
            factorprime = 2; 
            countsumprime=0;
            while (factorprime * factorprime <= tempprime) {
                while (tempprime % factorprime == 0) {
                    tempprime /= factorprime;
                    countsumprime++;
                }
                if (factorprime == 2) {              //prime
                    factorprime = 3;                 //factor
                }                                    //code part
                else if (factorprime == 3) {
                    factorprime = 5;
                }
                else if (factorprime % 6 == 5) {
                    factorprime += 2;
                }
                else {
                    factorprime += 4;
                }
            }
            if (tempprime != 1) {
                countsumprime++;
            }
            if (countsumprime % 2 == 0){
                Mertens++;
                if(Mertens == 0) {
                    ZP++;
                }
                if(n >= tenK -9 && n <= tenK +9 ){
                    printf("M(%d) = %d\n",nprime,Mertens); 
                    //here prints the third condition where mobius = 1 
                    //and Mertens is +1 from previous condition
                }
                if(n == tenMAXEXP +9){
                    break;
                }
                if(n == tenK + 9){
                    printf("..........\n");
                    tenK *= 10;
                }
            }
            else {
                Mertens--;
                if(Mertens == 0) {
                    ZP++;
                }
                if(n >= tenK -9 && n <= tenK +9 ){
                    printf("M(%d) = %d\n",nprime,Mertens); 
                    //here prints the fourth condition where mobius = -1
                    //and Mertens is -1 from previous condition
                }
                if(n == tenMAXEXP +9){
                    break;
                }
                if(n == tenK + 9){
                    printf("..........\n");
                    tenK *= 10;
                }
            }
        }
    }
    printf("\nFound %d zero points of the Mertens function\n",ZP);
    //This is the zero points part of the code
    //Here it finds the amount of abundant, deficient and perfect numbers
    //inside a specific dimension of numbers determined by how many zero points we have
    printf("\nChecking numbers in the range [2,%d]\n\n",ZP*1000);
    for (nZP = 2 ; nZP <= ZP * 1000 ; nZP++) {
        sumdiv = 1;
        for (DivisorZP = 2 ; DivisorZP * DivisorZP < nZP ; DivisorZP++) {
            if (nZP % DivisorZP == 0) {
                //sum the number's divisor + the second divisor from the other side
                //used to speed up the process
                sumdiv += DivisorZP + (nZP / DivisorZP);
            }
        }
        if (DivisorZP * DivisorZP == nZP) {
            sumdiv += DivisorZP;
        }
        if (sumdiv < nZP) { 
            // if the sum of the number's divisors is smaller than the number itself
            // then it's a deficient number
            countdef++;
            continue;
        }
        else if (sumdiv > nZP) {
            // if the sum of the number's divisors is bigger than the number itself
            // then it's an abundant number
            countabund++;
            continue;
        }
        else {
            //if the sum of the number's divisor is equal to the number itself
            //then it's a perfect number
            printf("Found perfect number: %d\n",nZP);
        }
    }
    printf("\nFound %d deficient numbers\n",countdef);
    printf("Found %d abundant numbers\n",countabund);
}