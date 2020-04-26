#include <stdio.h>

typedef char string[255];

int main(void)
{
	string input;

	printf("What is your name?\n");
	scanf("%s", input);
	
	printf("Hello, %s!\n", input);
}
