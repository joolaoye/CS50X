#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumber;

    // ask input //
    do
    {
        cardnumber = get_long("input cardnumber: ");
    }

    // constraint //
    while (cardnumber < 1);

    int digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9, digit10, digit11, digit12, digit13, digit14, digit15, digit16;

    digit1 = (cardnumber % 10);
    digit2 = ((cardnumber % 100)/10)*2;
    digit3 = (cardnumber % 1000);
    digit4 = ((cardnumber % 10000)/1000)*2;
    digit5 = (cardnumber % 100000);
    digit6 = ((cardnumber % 1000000)/100000)*2;
    digit7 = (cardnumber % 10000000);
    digit8 = ((cardnumber % 100000000)/10000000)*2;
    digit9 = (cardnumber % 1000000000);
    digit10 = ((cardnumber % 10000000000)/1000000000)*2;
    digit11 = (cardnumber % 100000000000);
    digit12 = ((cardnumber % 1000000000000)/100000000000)*2;
    digit13 = (cardnumber % 10000000000000);
    digit14 = ((cardnumber % 100000000000000)/10000000000000)*2;
    digit15 = (cardnumber % 1000000000000000);
    digit16 = ((cardnumber % 10000000000000000)/1000000000000000)*2;

    digit2 = ((digit2 % 100)/10) + (digit2 % 10);
    digit4 = ((digit4 % 100)/10) + (digit4 % 10);
    digit6 = ((digit6 % 100)/10) + (digit6 % 10);
    digit8 = ((digit8 % 100)/10) + (digit8 % 10);
    digit10 = ((digit10 % 100)/10) + (digit10 % 10);
    digit12 = ((digit12 % 100)/10) + (digit12 % 10);
    digit14 = ((digit14 % 100)/10) + (digit14 % 10);
    digit16 = ((digit16 % 100)/10) + (digit16 % 10);

    int sum1 = digit2 + digit4 + digit6 + digit8 + digit10 + digit12 + digit14 + digit16;

    int sum2 = digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13 + digit15;

    int sum3 = sum1 + sum2;

    int length = 0;
    long VISA = cardnumber ;
    long AMEX = cardnumber ;
    long Mastercard = cardnumber ;

    while (cardnumber > 0)
    {
        cardnumber /= 10;
        length += 1;
    }

    while (VISA >= 10)
    {
        VISA = cardnumber/10;
        VISA ++;
    }
    if (VISA == 4 && (length == 13 || length == 16))
    {
        printf("Card is VISA\n");
    }
    else
    {
    while (AMEX >= 10000000000000)
    {
         AMEX = cardnumber/10000000000000;
    }
    if (length == 15 && (AMEX == 34 || AMEX == 37))
    {
         printf("Card is AMEX\n");
    }
    }

    }