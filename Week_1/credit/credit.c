#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long cardNo = get_long("Number : ");
    int cardLen = 0, sum = 0;
    long card = cardNo;

    while (cardNo != 0)
    {
        int lastDig = cardNo % 10;
        cardNo /= 10;

        if (cardLen % 2 == 0)
        {
            sum += lastDig;
        }
        else
        {
            lastDig *= 2;
            sum += ((lastDig / 10) + (lastDig % 10));
        }

        cardLen += 1;
    }


    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        int firstNum = card / pow(10, cardLen - 1);
        int secondNum = (card / pow(10, cardLen - 2));
        secondNum %= 10;

        switch (firstNum)
        {
            case 3:
                if (secondNum == 4 || secondNum == 7 && (cardLen == 15))
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            case 5:
                if (secondNum >= 1 && secondNum <= 5 && (cardLen == 16))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            case 4:
                if (cardLen == 13 || cardLen == 16)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            default:
                printf("INVALID\n");

        }
    }

}
