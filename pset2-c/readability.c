#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float calculate_average(int number, int words, int count);
float calculate_grade(float avg_letters, float avg_words);

int main(void)
{
    string text = get_string("Text: ");
    int size = strlen(text);

    int words = 1; // last word (count all spaces + 1)
    int letters = 0;
    int sentences = 0;

    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }



    float grade = calculate_grade(
                      calculate_average(letters, words, 100),
                      calculate_average(sentences, words, 100)
                  );

    if (grade < 1)
    {
        printf("Before Grade 1\n");

        return 0;
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");

        return 0;
    }

    printf("Grade %i\n", (int) round(grade));
}

float calculate_grade(float avg_letters, float avg_words) //Coleman-Liau index
{
    return 0.0588 * avg_letters - 0.296 * avg_words - 15.8;
}

float calculate_average(int number, int words, int count)
{
    return (float) number * (float) count / (float) words;
}

