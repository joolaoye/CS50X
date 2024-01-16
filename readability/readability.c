#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

float count_characters(string text);
float count_letters(string text, float  length);
float  count_words(string text, float  length);
float  count_sentences(string text, float  length);
int main(void)
{
    string text = get_string("Input text: ");
    float  length = count_characters(text);
    float  letters = count_letters(text, length);
    float  words = count_words(text, length);
    float  sentences = count_sentences(text, length);
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    double index = ((0.0588 * L) - (0.296 * S)) - 15.8;
    int rindex = round(index);

    printf("\n");
    printf("Text: %s\n", text);
    if (rindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rindex >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rindex);
    }
}
float  count_characters(string text)
{
    float length = strlen(text);
    return length;
}
float count_letters(string text, float length)
{
    float letters = 0;
    for (int a = 0; a < length; a++)
    {
        if (isalpha(text[a]))
        {
            letters++;
        }
    }
    return letters;
}

float count_words(string text, float length)
{
    float words = 1.00;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
float count_sentences(string text, float length)
{
    float  sentences = 0;
    for (int j = 0; j < length; j++)
    {
        if (text[j] == '.' || text[j] == '?' || text[j] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

