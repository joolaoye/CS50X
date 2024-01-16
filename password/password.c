// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool caps = false;
    bool lower = false;
    bool num = false;
    bool symbol = false;



    for (int i = 0; i < strlen(password); i++){
        int val = (int) password[i];

        if ((65 <= val) && (val <= 90)){
            caps = true;
        }

        else if ((97 <= val) && (val <= 122)){
            lower = true;
        }

        else if ((48 <= val) && (val <= 57)){
            num = true;
        }

        else if ((32 <= val) && (val <= 127)){
            symbol = true;
        }
    }

    return caps && lower && num && symbol;
}
