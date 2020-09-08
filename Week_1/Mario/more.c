#include <stdio.h>
#include <cs50.h>

//Functions
void pyramid(int num);

//main function
int main(void)
{

    int num;

    do
    {
        num = get_int("Please enter a number : ");
    }
    while (num < 1 || num > 8);

    pyramid(num);

}

//Function for the stairs
void pyramid(int num)
{
    
    //Loop for each line
    for (int i = 0; i < num; i++)
    {
        //----    First pyramid    ---- Start
        for (int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //----    First pyramid    ---- End
        
        printf("  ");                 //For the gap
        
        //----    Second pyramid   ---- Start
        for (int j = 0; j <= i; j++)  
        {
            printf("#");
        }
        //----    Second pyramid   ---- End
        
        printf("\n");                 //New line
        
    }

}
