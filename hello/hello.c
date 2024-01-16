#include <cs50.h>
#include <stdio.h>

int main()
{
    string name = get_string("Input name: ");  // Prompts user for name//
    printf("Hello, %s\n", name);  // Prints Hello, user name
}