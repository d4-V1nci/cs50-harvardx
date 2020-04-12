#include <cs50.h> // get_string
#include <stdio.h> // printf
#include <string.h> // strlen
#include <ctype.h> //islower, toupper

int validate_input_or_exit(int argc, string argv[]);
bool between_or_equals(int to_check, int min, int max);

int main(int argc, string argv[])
{
    if (validate_input_or_exit(argc, argv))
    {
        return 1;
    }

    string key = argv[1];
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        int letter = (int) text[i]; // letter to substitute

        if (between_or_equals(letter, 'A', 'Z') || between_or_equals(letter, 'a', 'z'))
        {
            int is_lower = islower(letter); // check is lower
            int zero_index = is_lower ? 'a' : 'A';
            int replace_to = letter - zero_index;

            printf("%c", is_lower ? tolower(key[replace_to]) : toupper(key[replace_to]));

            continue;
        }

        printf("%c", letter);
    }

    printf("\n");

    return 0;
}

int validate_input_or_exit(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    string key = argv[1];
    int len = strlen(key);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");

        return 1;
    }

    int check_sum = 2015;
    int sum = 0;
    for (int i = 0; i < len; i++) //TODO: Algo is not optimal; Rethink this.
    {
        char letter = toupper(key[i]);
        sum += (int) letter;

        for (int j = 0; j < len; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (letter == toupper(key[j]))
            {
                printf("Duplicates are not allowed\n");

                return 1;
            }
        }
    }

    if (check_sum != sum)
    {
        printf("Only alphabet letters allowed\n");

        return 1;
    }


    return 0;
}

bool between_or_equals(int to_check, int min, int max)
{
    return (to_check >= min) && (to_check <= max);
}
