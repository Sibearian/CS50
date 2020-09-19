#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

//Prototypes
void encrypt(char letter, int key);
int check_key_string(string k);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = check_key_string(argv[1]);

    if (key == -1)
    {
        return 1;
    }

    string plain_text = get_string("plaintext :  ");

    printf("ciphertext : ");

    for (int i = 0; plain_text[i] != '\0'; i++)
    {
        encrypt(plain_text[i], key);
    }

    printf("\n");


}


/*
-------------------- encrypt --------------------
A function to encrypt alphabet

-This function will take a single character a time.
-It will encrypt every ascii alpahbet (A - Z and a - z)
-It will NOT encrypt anything else

Params:
    (char, key)
    char - a ascii char should be passed
    key  - a integer should be passed

-------------------------------------------------*/

void encrypt(char letter, int key)
{
    if (letter > 64 && letter < 91)
    {
        int print = ((letter - 64) + key) % 26;
        print += 64;
        printf("%c", print);
    }
    else if (letter > 96 && letter < 123)
    {
        int print = ((letter - 96) + key) % 26;
        print += 96;
        printf("%c", print);
    }
    else
    {
        printf("%c", letter);
    }

}


/*
---------- check_key_string ----------
A function to check if the key has any problem

-It checks if the key has a ascii character that is NOT a digit

params:
    (string)
    k - a string of potential number
--------------------------------------*/

int check_key_string(string k)
{
    for (int i = 0; k[i] != '\0'; i++)
    {
        if (!(isdigit(k[i])))
        {
            return -1;
        }
    }

    return (int) atoi(k);

}
