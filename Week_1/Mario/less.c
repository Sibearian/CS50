#include <stdio.h>
#include <cs50.h>

//Prototypes
void stair_down_to_top(int num);

//Main Function
int main(void)
{
    int num;

    do
    {
        num = get_int("Please enter a number : ");
    }
    while (num < 1 || num > 8);

    stair_down_to_top(num);

}


//Function for the stairs
void stair_down_to_top(int num)
{

    for (int i = 0; i < num; i++)               //This loop makes
    {

        for (int j = 0; j < num - i; j++)       //Loop for the space bars
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)         //Loop for the #
        {
            printf("#");
        }

        printf("\n");                           //For a new line

    }
}
