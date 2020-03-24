#include <cs50.h>
#include <stdio.h>

int main(void) { 
    // Ask user for input 
    string name = get_string("What is your name?\n");
    // Say hello to user value
    printf("hello, %s\n", name);
}