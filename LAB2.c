/*
 ============================================================================
 Name        : Lab2.c
 Author      : Austin Tian
 Description : Signed number and unsigned numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 32   // maximum size of the binary number is 32 bit.
#define number1 "11000001010010000000000000000000"
#define number2 "01000001010101000000000000000000"

void convert_binary_to_signed(const char *binary);
void convert_binary_to_float(const char *binary);

char *menu =
"\n"
"\n"
"===================================================================\n"
"************Please select the following options********************\n"
" *    1. Binary number to signed decimal number conversion.(Lab 2) *\n"
" *    2. Binary number to Floating number conversion (Lab 2)       *\n"
" *******************************************************************\n"
" *    e. To Exit, Type 'e'                                         *\n"
" *******************************************************************\n";

int main(void)
{
    char options;                 // the option should only be a byte
    char inputs[33] = {0};        // 32-bit string plus ending character

    do
    {
        puts(menu);
        fflush(stdin);
        options = getchar();

        switch (options)
        {
            case '1':
                puts("Please input your BINARY number, I will convert it to signed decimal:");
                scanf("%s", &inputs[0]);
                convert_binary_to_signed(inputs);
                continue;

            case '2':
                puts("Please input your 32-bit floating point number in binary:");
                scanf("%s", &inputs[0]);
                convert_binary_to_float(inputs);
                continue;

            case 'e':
                puts("Code finished, exit now");
                return EXIT_SUCCESS;

            default:
                puts("Not a valid entry, exit now");
                continue;
        }
    } while (1);
}

/*
 * Function: convert_binary_to_signed, To Do: Convert an 8-bit binary string into a signed decimal number
 */
void convert_binary_to_signed(const char *binary)
{
    int deci = 0;
    int i;
    int len = strlen(binary);

    if (len < 8)
    {
        printf("Error: Please enter at least 8 bits.\n");
        return;
    }

    /* Use only the last 8 bits */
    const char *b = binary + (len - 8);

    for (i = 0; i < 8; i++)
    {
        deci = deci << 1;
        if (b[i] == '1')
        {
            deci += 1;
        }
    }

    /* Two's complement handling */
    if (b[0] == '1')
    {
        deci -= 256;
    }

    printf("Signed decimal value: %d\n", deci);
}

/*
 * Function: convert_binary_to_float, To-Do : Convert a 32-bit IEEE-754 binary string to float-point number
 */
void convert_binary_to_float(const char *binary)
{
    int sign;
    int exponent = 0;
    float mantissa = 1.0f;
    int i;

    /* Determining sign */
    sign = (binary[0] == '1') ? -1 : 1;

    /* Calculating exponent */
    for (i = 1; i <= 8; i++)
    {
        exponent = exponent << 1;
        if (binary[i] == '1')
        {
            exponent += 1;
        }
    }
    exponent -= 127;

    /* Calculating mantissa */
    for (i = 9; i < 32; i++)
    {
        if (binary[i] == '1')
        {
            mantissa += pow(2, -(i - 8));
        }
    }

    /* Finalling float-point result */
    float result = sign * mantissa * pow(2, exponent);
    printf("Float-point value: %f\n", result);
}

