#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <regex.h>

int get_number_len(long number) 
{ 
    int len = floor(log10(number)) + 1;

    return len;
}

long *number_to_array(long number)
{ 
    int len = get_number_len(number);
    long *result;
    result = (long *) malloc(len * sizeof(long));
    
    for (int i = len; i > 0; i--) 
    { 
        result[len - i] = (long)(number / pow(10, i - 1)) % 10;
    }
    
    return (result);
}

bool is_card_valid(long card) // Luhn algorithm
{ 
    int len = get_number_len(card);
    long *number = number_to_array(card);
    int parity = len % 2;
    
    int sum = 0;
    
    for (int i = 0; i < len; i++) 
    { 
        int digit = number[i];
        if (i % 2 == parity) 
        { 
            digit *= 2;
        }

        if (digit > 9) 
        { 
            digit -= 9;
        }
        sum += digit;
        
    }
    free(number);

    return sum % 10 == 0;
}

int main(void)
{ 
    long card = get_long("Number: ");
    int len = get_number_len(card);

    if ((len == 13 || len == 15 || len == 16) && is_card_valid(card)) 
    { 
        long *number = number_to_array(card);

        // Visa len: 13 or 16-digit - start num:  4
        if ((len == 13 || len == 16))
        {
            if (number[0] == 4) 
            { 
                printf("VISA\n");
                return 0;
            }
        }
        
        // MasterCard 16-digit - start numbers 51, 52,53, 54 or 55
        if (len == 16) 
        { 
            if (number[0] == 5 && number[1] >= 1 && number[2] <= 5) 
            { 
                printf("MASTERCARD\n");
                return 0;
            }
        }
        
        // American express 15-digit - start numbers 34 or 37
        if (len == 15)
        { 
            if (number[0] == 3 && (number[1] == 4 || number[1] == 7)) 
            {
                printf("AMEX\n");
                return 0;
            }
        }
    }

    printf("INVALID\n");
}
