//Abdalla Kharoub
//665282497

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/convert.h"
#include <stdlib.h>
/*

NUMBER CONVERSION
Convert any radix input to unisgned integer or unsgned ineteger to 
any other radix chosen by the user
Emphasis on binary decimal octal and hexadecimal

*/

// Driver program 
int main()
{
    int choice;
    int dNumber; // To store the decimal number for conversion
    int radix;   // To store the radix
    char other[SIZE]; // To store the user's input
    int check; // To store return value of isRadix function

    // options for the user
    printf("Choose one from the following choices \n");

    do {
        printf("1 :Convert unsigned integer to any Other Radix (binary 2, Octal 8, Hexadecimal 16).\n"
               "2 :Convert From any Radix (binary 2, Octal 8, Hexadecimal 16) to unsigned integer number.\n");

        scanf("%d", &choice);

    } while (choice < 1 || choice > 2); 


    switch (choice) {

        case 1:

            printf("Enter an unsigned integer in decimal: ");
            scanf("%d", &dNumber); 

            printf("Enter the radix you want to convert it to (binary = 2, octal = 8, and hexadecimal = 16): ");
            scanf("%d", &radix); 

            // Call decimalToOther to perform conversion and store result
            char *result = decimalToOther(dNumber, radix);

       
            printf("The number converted is: %s\n", result);
        
            // freeing memory allocated array
            free(result); 

            break;

        case 2:

            printf("Enter the number you would like to be converted to decimal: ");
            scanf("%s", other); 

            printf("Enter the radix of the number (binary = 2, octal = 8, and hexadecimal = 16): ");
            scanf("%d", &radix); 

            check = isRadix(other, radix);

            // Check if input number is valid for the given radix
            while (check == 0) {

                printf("\n");

                printf("The input number is not valid for the specified radix.\n");

                printf("Enter the radix of the number (binary = 2, octal = 8, and hexadecimal = 16): ");
                scanf("%d", &radix);

                check = isRadix(other, radix);
                
            }


            // Convert the input to decimal and store
            int convertedNum = otherToDecimal(radix, other);

          
            printf("The number converted is: %d\n", convertedNum);
            break;
    }

    return 0; 
}

