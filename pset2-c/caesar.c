#include <ctype.h> // isdigit
#include <cs50.h> // get_string
#include <stdio.h> // printf
#include <string.h> // strlen
#include <stdlib.h> // atoi

bool is_valid_input(int argc, string argv[]);

int main(int argc, string argv[])
{
    if (!is_valid_input(argc, argv))
    {
        printf("Usage: ./caesar key\n");
        
        return 1;
    }

    int k = atoi(argv[1]) % 26;


    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        int letter = (int) text[i];

        if (
            (letter >= 'A' && letter <= 'Z') ||
            (letter >= 'a' && letter <= 'z')
        )
        {
            letter += k;

            if ((letter > 'Z' && letter < 'a') || letter > 'z') 
            {
                letter -= 26;
            }
        }

        printf("%c", letter);
    }

    printf("\n");

    return 0;
}

bool is_valid_input(int argc, string argv[])
{
    if (argc != 2)
    {
        return false;
    }

    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            return false;
        }
    }

    return true;
}