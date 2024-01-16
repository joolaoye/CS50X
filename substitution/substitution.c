//Program encrypts user input with the alphabetical key entered on the coommand line//
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//Array of lowercase characters//
char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'
                   };
//Array of uppercase characters//
char caps_alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                         'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                        };
bool only_letters(string argv);
bool duplicate(string word);
int main(int argc, string argv[])
{
    //Checks if command argument is 2//
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Checks if key is 26 characters//
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Checks if Alphabetical key contains non-alphabetical chars//
    else if (!only_letters(argv[1]))
    {
        printf("Must be alphabetical characters\n");
        return 1;
    }
    //Checks if the same char appears more than once in the key//
    else if (!duplicate(argv[1]))
    {
        return 1;
    }
    else
    {
        //Assigns argv[1](alphabetical key) to key//
        string key = argv[1];

        //Gets user's input//
        string plaintext = get_string("Plaintext: ");
        int length = strlen(plaintext);

        //Array that stores encrypted characters//
        char ciphertext[length];

        for (int i = 0; i < length; i++)
        {
            //Condition that encrypts only alphabetical chars from plaintext//
            if (isalpha(plaintext[i]))
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plaintext[i] == alphabets[j])
                    {
                        ciphertext[i] = tolower(key[j]);
                    }
                    else if (plaintext[i] == caps_alphabets[j])
                    {
                        ciphertext[i] = toupper(key[j]);
                    }
                }
            }
            //Condtion for non-alphabetical chars from plaintext//
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        //Ends the string "ciphertext"//
        ciphertext[length] = '\0';

        printf("ciphertext: %s\n", ciphertext);
    }
}


//Function that checks if key contains non-alphabetical chars//
bool only_letters(string argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        if (!isalpha(argv[i]))
        {
            return false;
        }
    }
    return true;
}

//Function that checks if their is duplicate chars in a string//
bool duplicate(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = i + 1; j < strlen(word); j++)
        {
            if (word[i] == word[j])
            {
                return false;
            }
            else if (word[i] == tolower(word[j]))
            {
                return false;
            }
            else if (word[i] == toupper(word[j]))
            {
                return false;
            }
        }
    }
    return true;
}
