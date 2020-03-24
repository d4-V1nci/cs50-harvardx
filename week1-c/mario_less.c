#include <cs50.h>
#include <stdio.h>

void printPyramid(int height) 
{ 
    char line[height]; //initialize char array
    for (int i = 0; i < height; i++) 
    { 
        line[i] = ' ';
    }

    for (int i = height-1; i >= 0; i--) 
    { 
        line[i] = '#';
        printf("%s\n", line);
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
