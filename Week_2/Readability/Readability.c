#include <stdio.h>
#include <math.h>
#include <cs50.h>

//prototypes
int num_letters(string text);
int num_words(string text);
int num_sentance(string text);

//main
int main(void)
{
    string text = get_string("TEXT : ");

    float Letters = (num_letters(text) / (float) num_words(text)) * 100;
    float Sentance = (num_sentance(text) / (float) num_words(text)) * 100;

    int index = round(0.0588 * Letters - 0.296 * Sentance - 15.8);
    
    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

//Function to count letters (Letters are 'a' to 'Z')
int num_letters(string text)
{
    int letters = 0;
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 65 && text[i] <= 122)
        {
            letters++;
        }
    }
    
    return letters;
}

//Function to count words (words are seperated by ' ')
int num_words(string text)
{
    int words = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    
    return words;
}

//Function to sentance (sentance are seperated by '.' '!' '?')
int num_sentance(string text)
{
    int sentance = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentance++;
        }
    }

    return sentance;
}
