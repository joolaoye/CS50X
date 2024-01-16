//Program Checks the Validity of Credit Card//
#include <cs50.h>
#include <stdio.h>

long get_card();
int get_length(long card);
int main()
{
    long card = get_card(); //Gets card number from user//

    int length = get_length(card); //Calculates card length//

    int digit[length]; //Each digits of the card stored in an array//

    int luhn_digit[length]; //Each alternating digits stored in an array//

    for (int i = 0; i < length; i++) //Gets each digits//
    {
        if (card > 0)
        {
            digit[i] = card % 10;
        }
        card /= 10;
    }

    for (int i = 1, j = 0; i <= length && j < length / 2; i += 2, j++) //Gets each alternating digits//
    {
        luhn_digit[j] = digit[i] * 2;

        if (luhn_digit[j] > 9)
        {
            luhn_digit[j] = (luhn_digit[j] / 10) + (luhn_digit[j] % 10);
        }
    }

    int sum_1 = 0; // Sum of all digits excluding the alternating digits//
    for (int i = 0; i < length; i += 2)
    {
        sum_1 += digit[i];
    }

    int sum_2 = 0; // Sum of all alternating digits//
    for (int j = 0; j < length; j++)
    {
        sum_2 += luhn_digit[j];
    }

    int sum_3 = (sum_1 + sum_2) % 10;

    //TEST 1//
    if (sum_3 == 0 && length > 0)
    {
        //TEST 2//
        if ((length == 13 || length == 16) && (digit[12] == 4 || digit[15] == 4)) //Checks for VISA//
        {
            printf("VISA\n");
        }
        else if ((length == 16) && (digit[15]) == 5 && (digit[14] == 1 || digit[14] == 2 || digit[14] == 3 || digit[14] == 4
                 || digit[14] == 5)) //Checks for MASTERCARD//
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 15) && (digit[14] == 3) && (digit[13] == 4 || digit[13] == 7)) //Checks for AMEX//
        {
            printf("AMEX\n");
        }
        else //Passes test 1 but fails test 2//
        {
            printf("INVALID\n");
        }
    }
    else //Fails test1//
    {
        printf("INVALID\n");
    }
}

long get_card() //Function get_card()//
{
    long card;
    do
    {
        card = get_long("Input card number: ");
    }
    while (card < 1);

    return card;
}

int get_length(long card) //Function get_length//
{
    int length = 0;
    while (card > 0)
    {
        card = card / 10;
        length++;
    }
    return length;
}