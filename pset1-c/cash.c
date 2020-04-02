#include <math.h>
#include <cs50.h>
#include <stdio.h>

int count_pennies(int coins) 
{ 
    int count_of_pennies = 0;
    int available_pennies[] = { 25, 10, 5, 1 };
    int mod = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (coins < available_pennies[i]) 
        { 
            continue;
        }

        count_of_pennies += (int) coins / available_pennies[i];
        coins = coins % available_pennies[i];
    }

    return count_of_pennies;
}

int main(void) 
{ 
    float dollars = 0;
    do 
    { 
        dollars = get_float("Change owed: ");
    } 
    while (dollars < 0);

    int coins_count = count_pennies(round(dollars * 100));
    
    printf("%d\n", coins_count);
}
