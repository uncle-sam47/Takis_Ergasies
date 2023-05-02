#include <stdio.h>
#include <ctype.h>

int CharactersIntoIntegerNumbers() {                                   //Function for reading a string of numbers and
    int Number = 0;                                                              //turning it into an interger number
    int ch = getchar();
    while (isspace(ch) == 0) {  //Aslong as (isspace ch ==0) means that it's reading something other than white space
        if (ch >= 48 && ch <= 57) {  //If the Ascii code of the character read is between 48 and 57 then its a number
            Number = 10*Number + ch - 48;             //multiply the previous number by 10 then add (Ascii code - 48)
            ch = getchar();
        }
        else {                                    //If character read is not between 48 and 57 then it's not a number
            break;
        }
    }
    ungetc(ch,stdin);                                                //Return what was previously read as input again
    return Number;                                                     //Return the actual whole number as an integer
}

void IgnoreCommentSections() {   //Function for reading comments in the header of the file only if there is a comment
    int ch = getchar();
    while (ch == '#') {                                                     //If it reads # in the begening of a line
        while(ch != '\n') {                               //Keep reading until it reads \n which indicates a new line
            ch = getchar();
        }
        ch = getchar();
    }
    ungetc(ch, stdin);                                               //Return what was previously read as input again
}

int IgnoreBlancSpace () {                    //Function for reading space ,white ,blank ,tab and \n and ignoring them
    int a;
    while ((a = getchar()) != EOF) {
        if(isspace(a)) {                       //If isspace(a) doesn't equal to 0 means that it's reading blank space
            continue;
        }
        else {
            ungetc(a, stdin);                                        //Return what was previously read as input again
            break;                                                                                    //Stop the loop
        }
    }
}



                                                                                                    //Bonus functions


void P6toP3(int height, int width) {
    int i,  j;
    for (i = 1; i <= height ; i++) {
        for (j = 1; j <= width ; j++) {
            int R = getchar();                                                //Read the red value and assign it to R
            printf("%d ",R);
            int G = getchar();                                              //Read the green value and assign it to G
            printf("%d ",G);
            int B = getchar();                                               //Read the blue value and assign it to B
            printf("%d",B);
            if (j < width)
                printf(" ");
        }
        if (i < height)
            printf("\n");
    }

}

void P5toP2(int height, int width) {
    int i,  j;
    for (i = 1; i <= height ; i++) {
        for (j = 1; j <= width ; j++) {
            int G = getchar();                                               //Read the gray value and assign it to G
            printf("%d",G);
            if (j < width)
                printf(" ");
        }
        if (i < height)
            printf("\n");
    }
}

void P4toP1(int height, int width) {
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int B = getchar();
            for (k = 0; k < 8; k++) {
                /*if (B % 2 == 0) {
                    putchar('0');
                    putchar(' ');
                }
                else {
                    putchar('1');
                    putchar(' ');
                }
                B /= 2;*/
                if (B & 128 == 128) {
                    putchar('1');
                    //putchar(' ');
                }
                else {
                    putchar('0');
                    //putchar(' ');
                }
                B << 1;
            }
        }
    }

}

void P3toP6(int height, int width) {
    int i,  j;
    for (i=0; i< height ; i++) {
        for (j = 0; j < width ; j++) {
            int R = CharactersIntoIntegerNumbers();          //Read the red value using a function and assign it to R
            putchar(R);
            IgnoreBlancSpace();
            int G = CharactersIntoIntegerNumbers();        //Read the green value using a function and assign it to G
            putchar(G);
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
            int B = CharactersIntoIntegerNumbers();         //Read the blue value using a function and assign it to B
            putchar(B);
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
        }
    }
}

void P2toP5(int height, int width) {
int i,  j;
    for (i=0; i< height ; i++) {
        for (j = 0; j < width ; j++) {
            int G = CharactersIntoIntegerNumbers();          //Read the red value using a function and assign it to R
            putchar(G);
            IgnoreBlancSpace();
        }
    }
}

void P1toP4(int height, int width) {


}





                                                                                                 //No Bonus functions


void P6toP5(int height, int width) {                                             //Main P6 into P5 converter Function
    int i,  j;
    for (i=0; i< height ; i++) {
        for (j = 0; j < width ; j++) {
            int R = getchar();                                                //Read the red value and assign it to R
            int G = getchar();                                              //Read the green value and assign it to G
            int B = getchar();                                               //Read the blue value and assign it to B
            int GrayGrade = (299*R + 587*G + 114*B) / 1000;  //Calculate the Grey grade from the values of R ,G and B
            putchar(GrayGrade);                                          //Print out the value of GrayGrade in binary
        }
    }

}

void P5toP4(int height, int width,int size) {                                    //Main P5 into P4 converter Function
    int i, j, k, ch, BlackAndWhiteByte;
    for (i = 0; i < height; i++ ) {
        for (j = 0;j < width; j += 8) {
            BlackAndWhiteByte = 0;
            for (k = 0; k < 8; k++) {
                ch = getchar();
                BlackAndWhiteByte *= 2;
                if (ch <= (size + 1)/2) {
                    BlackAndWhiteByte++;
                }
            }
            putchar(BlackAndWhiteByte);    //Print out the value of black and white in the form of 8 pixels in a byte
        }
    }
}

void P3toP2(int Height,int Width) {                                              //Main P3 into P2 converter Function
    int i, j;
    for (i = 0; i < Height; i++) {
        for (j = 0; j < Width; j++) {
            int R = CharactersIntoIntegerNumbers();          //Read the red value using a function and assign it to R
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
            int G = CharactersIntoIntegerNumbers();        //Read the green value using a function and assign it to G
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
            int B = CharactersIntoIntegerNumbers();         //Read the blue value using a function and assign it to B
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
            int GrayGrade = (299*R + 587*G + 114*B) / 1000;
            printf("%d ",GrayGrade);               //Print out the result of GrayGrade in a readable clear textf form
        }
        putchar('\n');
    }
}

void P2toP1(int Height, int Width, int Size) {                                   //Main P2 into P1 converter Function
    int i, j;
    for (i = 0; i < Height; i++) {
        for (j = 0; j < Width; j++) {
            IgnoreBlancSpace();                            //Ignoring the blanc space using IgnoreBlancSpace function
            int G = CharactersIntoIntegerNumbers();         //Read the gray value using a function and assign it to G
            if (G > (Size + 1)/2 ) {
                putchar('0');
                putchar(' ');
            }
            if (G <= (Size + 1)/2 ) {
                putchar('1');
                putchar(' ');
            }
        }
        putchar('\n');
    }
}





                                                                                  //Main program that is going to run
int main () {
    
    int ch = 0,MagicNum =0; //Magic Number is a variable given by the file which decides what type of file we work on
    int size = 0;
    int Bonus = 0;   //Bonus is the project last bonus part where if bonus = 1 means that the bonus part is initiated
    

    if (Bonus == 0) {            //If bonus = 0 then that means that normal image color conversion program is running
        ch = getchar();
        if (ch != 'P') {                                    //Check if the first letter of the file is the letter 'P'
            fprintf(stderr,"File type contents are not valid");                            //Display an error message
            return 0;                                                                               //End the program
        }
        putchar('P');
        
        ch = getchar();
        MagicNum = ch - 48;                                                        //MagicNum is the number after 'P'
        
        if (ch == '3') {                                           //Has RGB colors, and file is written in text mode
            putchar('2');
        }
        else if (ch == '2') {                        //Has Shades of Gray as colors, and file is written in text mode
            putchar('1');
        }
        else if (ch == '1') {                       //Has Black and white as colors, and file is written in text mode
            fprintf(stdout,"This photo could not be converted, it is already in the lowest convertable form");
            return 0;                                            //End the program, as it cannot be converted anymore
        }
        else if (ch == '6') {                                    //Has RGB colors, and file is written in binary form
            putchar('5');
        }
        else if (ch == '5') {                      //Has Shades of Gray as colors, and file is written in binary form
            putchar('4');
        }
        else if (ch == '4') {                     //Has Black and white as colors, and file is written in binary form
            fprintf(stdout,"This photo could not be converted, it is already in the lowest convertable form");
            return 0;                                                                               //End the program
        }
        else {
            fprintf(stderr,"File type contents are not valid");                            //Display an error message
            return 0;                                            //End the program, as it cannot be converted anymore
        }

        putchar('\n');
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
        IgnoreCommentSections();
    
        int width = CharactersIntoIntegerNumbers();
        printf("%d ",width);                                                       //Print out the width of the image
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
    
        int height = CharactersIntoIntegerNumbers();
        printf("%d\n",height);                                                    //Print out the height of the image
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
    
        size = CharactersIntoIntegerNumbers();
        if ((MagicNum == 3)||(MagicNum == 6)) {                                            //If the MagicNum = 3 or 6
            printf("%d\n",size);                             //Print out the maximum size that a color value can take
        }
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function

        if (MagicNum == 6)
            P6toP5(height,width);                                              //First conversion state from P6 to P5

        else if (MagicNum == 5)
            P5toP4(height,width,size);                                        //Second conversion state from P5 to P4

        else if (MagicNum == 3)
            P3toP2(height,width);                                              //Third conversion state from P3 to P2

        else if (MagicNum == 2)
            P2toP1(height,width,size);                                        //Fourth conversion state from P2 to P1

        else
            fprintf(stderr,"Something is wrong with the file");
        return 0;                                                                           //The end of this program
    }


    else if (Bonus == 1) {
       ch = getchar();           //If bonus = 1 then that means that normal image color conversion program is running
        if (ch != 'P') {                                    //Check if the first letter of the file is the letter 'P'
            fprintf(stderr,"File type contents are not valid");                            //Display an error message
            return 0;                                                                               //End the program
        }
        putchar('P');
        
        ch = getchar();
        MagicNum = ch - 48;                                                        //MagicNum is the number after 'P'
        if (ch == '6') {                                         //Has RGB colors, and file is written in binary form
            putchar('3');
        }
        else if (ch == '5') {                      //Has Shades of Gray as colors, and file is written in binary form
            putchar('2');
        }
        else if (ch == '4') {                     //Has Black and white as colors, and file is written in binary form
            putchar('1');
        }
        else if (ch == '3') {                                      //Has RGB colors, and file is written in text mode
            putchar('6');
        }
        else if (ch == '2') {                        //Has Shades of Gray as colors, and file is written in text mode
            putchar('5');
        }
        else if (ch == '1') {                       //Has Black and white as colors, and file is written in text mode
            putchar('4');
        }
        else {
            fprintf(stderr,"File type contents are not valid");                            //Display an error message
            return 0;                                            //End the program, as it cannot be converted anymore
        }
        
        putchar('\n');
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
        IgnoreCommentSections();
    
        int width = CharactersIntoIntegerNumbers();
        printf("%d ",width);                                                       //Print out the width of the image
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
    
        int height = CharactersIntoIntegerNumbers();
        printf("%d\n",height);                                                    //Print out the height of the image
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function
    
        if ((MagicNum == 6)||(MagicNum == 5)||(MagicNum == 3)||(MagicNum == 2)) { //If the MagicNum = 6, =5, =3 or =2
            size = CharactersIntoIntegerNumbers();
            printf("%d\n",size);                             //Print out the maximum size that a color value can take
        }
        IgnoreBlancSpace();                                //Ignoring the blanc space using IgnoreBlancSpace function

        if (MagicNum == 6)
            P6toP3(height,width);                                              //First conversion state from P6 to P3

        else if (MagicNum == 5)
            P5toP2(height,width);                              		      //Second conversion state from P5 to P2

        else if (MagicNum == 4)
            P4toP1(height,width);                                              //Third conversion state from P2 to P1

        else if (MagicNum == 3)
            P3toP6(height,width);                                             //Fourth conversion state from P3 to P6

        else if (MagicNum == 2)
            P2toP5(height,width);                                  	       //Fifth conversion state from P2 to P5

        else if (MagicNum == 1)
            P1toP4(height,width);                                              //Sixth conversion state from P1 to P4

        else
            fprintf(stderr,"Something is wrong with the file");
        return 0;                                                                           //The end of this program
    }
}