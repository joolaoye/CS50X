#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool only_digits(string argv);
int main(int argc, string argv[])
{
    //Exits code if command line argument is more than 2 or there is non-digit in key//
    if (argc != 2 || !(only_digits(argv[1])))
    {
        return 1;
    }
    //if user types correct command line argument//
    else
    {
        string argument = argv[1];
        int length = strlen(argument);

        //New array to store key characters//
        char digit[length];

        //Gets input from user//
        string plaintext = get_string("Plaintext: ");
        int str_l = strlen(plaintext);

        //New array to store encrypted chars//
        char ciphertext[str_l];

        //Declaring key//
        int key = 0;

        //Evaluates the string argv[1] to int key//
        if (length == 2)
        {
            for (int i = 0; i < length; i++)
            {
                digit[i] = argument[i];
                digit[i] = ((int) digit[i]) - 48;
            }
            key = (digit[0] * 10) + digit[1];

        }
        else if (length == 1)
        {
            digit[0] = argument[0];
            digit[0] = ((int) digit[0]) - 48;

            key = digit[0];
        }

        //Encrypts plaintext chars//
        for (int i = 0;  i < str_l; i++)
        {
            int character;
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    character = plaintext[i] - 65;
                    ciphertext[i] = ((character + key) % 26) + 65;
                }
                else
                {
                    character = plaintext[i] - 97;
                    ciphertext[i] = ((character + key) % 26) + 97;
                    ciphertext[i] = (char) ciphertext[i];
                }
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }

        //Line of code that ends the string ciphertext//
        ciphertext[str_l] = '\0';

        printf("ciphertext: %s\n", ciphertext);
    }
}

// Boolean function that checks if a char in digit is non-digit//
bool only_digits(string argv)
{
    int length = strlen(argv);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}