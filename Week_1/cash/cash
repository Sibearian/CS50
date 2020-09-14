#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float dollars;
    int coins = 0;

    do
    {
        dollars = get_float("dollars Owned : ");
    }
    while (dollars < 0);

    int change = round(dollars * 100);

    while (change >= 25)
    {
        change -= 25;
        coins++;
    }
    while (change >= 10)
    {
        change -= 10;
        coins++;
    }
    while (change >= 5)
    {
        change -= 5;
        coins++;
    }
    while (change >= 1)
    {
        change -= 1;
        coins++;
    }

    printf("%d", coins);

}
