#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int length = strlen(word);
    char alphabet[length - 1];

    for (int i = 0; i < length; i++)
    {
        alphabet[i] = tolower(word[i]);
        if (isalpha(alphabet[i]))
        {
            if (alphabet[i] == 'a')
            {
                alphabet[i] = (int) POINTS[0];
            }
            if (alphabet[i] == 'b')
            {
                alphabet[i] = (int) POINTS[1];
            }
            if (alphabet[i] == 'c')
            {
                alphabet[i] = (int) POINTS[2];
            }
            if (alphabet[i] == 'd')
            {
                alphabet[i] = (int) POINTS[3];
            }
            if (alphabet[i] == 'e')
            {
                alphabet[i] = (int) POINTS[4];
            }
            if (alphabet[i] == 'f')
            {
                alphabet[i] = (int) POINTS[5];
            }
            if (alphabet[i] == 'g')
            {
                alphabet[i] = (int) POINTS[6];
            }
            if (alphabet[i] == 'h')
            {
                alphabet[i] = (int) POINTS[7];
            }
            if (alphabet[i] == 'i')
            {
                alphabet[i] = (int) POINTS[8];
            }
            if (alphabet[i] == 'j')
            {
                alphabet[i] = (int) POINTS[9];
            }
            if (alphabet[i] == 'k')
            {
                alphabet[i] = (int) POINTS[10];
            }
            if (alphabet[i] == 'l')
            {
                alphabet[i] = (int) POINTS[11];
            }
            if (alphabet[i] == 'm')
            {
                alphabet[i] = (int) POINTS[12];
            }
            if (alphabet[i] == 'n')
            {
                alphabet[i] = (int) POINTS[13];
            }
            if (alphabet[i] == 'o')
            {
                alphabet[i] = (int) POINTS[14];
            }
            if (alphabet[i] == 'p')
            {
                alphabet[i] = (int) POINTS[15];
            }
            if (alphabet[i] == 'q')
            {
                alphabet[i] = (int) POINTS[16];
            }
            if (alphabet[i] == 'r')
            {
                alphabet[i] = (int) POINTS[17];
            }
            if (alphabet[i] == 's')
            {
                alphabet[i] = (int) POINTS[18];
            }
            if (alphabet[i] == 't')
            {
                alphabet[i] = (int) POINTS[19];
            }
            if (alphabet[i] == 'u')
            {
                alphabet[i] = (int) POINTS[20];
            }
            if (alphabet[i] == 'v')
            {
                alphabet[i] = (int) POINTS[21];
            }
            if (alphabet[i] == 'w')
            {
                alphabet[i] = (int) POINTS[22];
            }
            if (alphabet[i] == 'x')
            {
                alphabet[i] = (int) POINTS[23];
            }
            if (alphabet[i] == 'y')
            {
                alphabet[i] = (int) POINTS[24];
            }
            if (alphabet[i] == 'z')
            {
                alphabet[i] = (int) POINTS[25];
            }
        }
        else
        {
            alphabet[i] = (int) 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += alphabet[i];
    }
    return sum;
}
