#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //prompt user Usage: ./caesar key until argc = 2

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //prompt user Usage: ./caesar key until he enters integer

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    //get the text from user
    string plaintext = get_string("Plaintext: ");

    //print the cipheretext
    printf("ciphertext: ");

    //convert plaintext into cipheretext

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}