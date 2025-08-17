//Abdalla Kharoub
//665282497

#include "../include/convert.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int otherToDecimal(int radix, char *other)
{
    int size = strlen(other); // Find the length of the string

    int result = 0; 

    if (radix == 2) {

        for (int i = 0; i < size; i++) {

            // starts from the right side of the number
            char bit = other[size - 1 - i];  

            // converting char to integer using bit - 48
            // then multiplying it by 2 to the power of i
            // to convert binary num to dec num
            result += ((pow(2, i)) * (bit - 48));

        }
        return result;
    }
    else if (radix == 8) {

        for (int i = 0; i < size; i++) {
             
            char bit = other[size - 1 - i]; 

            result += (pow(8, i) * (bit - 48));
        }

        return result;
    }
    else if (radix == 16) {

        for (int i = 0; i < size; i++) {

            char bit = other[size - 1 - i];

            if (bit >= 48 && bit <= 57) {
                
                result += (pow(16, i) * (bit - 48));
            } 

            else if (bit >= 65 && bit <= 70) {

                // (bit - 'A' + 10) subtracts the char 'A'
                // from the char that is in bit
                // then adds 10 to get its integer val
                result += (pow(16, i) * (bit - 65 + 10));
            }
        }
        return result;
    }

    return -1; // Invalid radix
}


char* decimalToOther(int dnumber, int radix)
{
    // memory allocated temporary array
    // to store converted number
    char *other = calloc(SIZE, sizeof(other)); 

    if (other == NULL) {

        printf("Memory allocation failed \n");


    }



    // Convert decimal number to target radix
    for (int i = 0; dnumber > 0; i++) {

        int remainder = dnumber % radix;

        if (remainder < 10) {


            // converting integer remainder into char
            other[i] = remainder + 48; 
        }
        else {

            other[i] = remainder - 10 + 65; // Digits A-F
        }

        dnumber /= radix;
    }

    return reverse(other); // Reverse and return the string
}


char* reverse(char *other)
{
    int size = strlen(other); // Find the size of the string

    // Reverse the string in place
    for (int i = 0, j = size - 1; i < j; i++, j--) {

        // storing char in pos i in temp
        char temp = other[i];

        // replacing the char that was at pos i with
        // the char in pos j
        other[i] = other[j];

        // replacing character in pos j with
        // chat in temp
        other[j] = temp;
    }

    return other;
}


int isRadix(char *other, int radix)
{
    int size = strlen(other); // Find the size of the string

    // Check if each character is valid for the given radix
    for (int i = 0; i < size; i++) {

        char bit = other[i];

        if ((radix == 2 && (bit != 48 && bit != 49)) || 
            (radix == 8 && (bit < 48 || bit > 55)) || 
            (radix == 16 && !((bit >= 48 && bit <= 57) || (bit >= 65 && bit <= 70)))) {

            return 0; // Invalid radix
        }
    }

    return 1; // Valid radix
}
