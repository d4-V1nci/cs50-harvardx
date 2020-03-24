#include <cs50.h> // get_int
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

char *getReversedLine(char *line)
{ 
    size_t line_size = strlen(line);
    char *reversed = malloc(line_size);
    size_t last_index = line_size - 1;

    for (int i = 0; i < line_size; i++) 
    { 
        reversed[i] = line[last_index - i];
    }

    return reversed;
}

void printPyramid(int height) 
{ 
    char *line = malloc(height);
    for (int i = 0; i < height; i++) 
    { 
        line[i] = '.';
    }

    for (int i = height - 1; i >= 0; i--) 
    { 
        line[i] = '#';
        char *reversed = getReversedLine(line);
        printf("%s  %s\n", line, reversed);
        free(reversed);
    }
}

int main(void)
{
    int height = 0;

    do 
    { 
        height = get_int("Height: "); // read user input 
    } 
    while (height < 1 || height > 8); // Check if number in range
        
    printPyramid(height);
}
