#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int nArgs, char *args[])
{
    if (nArgs < 2)
    {
        printf("Please supply a key as an argument!\n");
        return 1;
    }
    else if (nArgs > 2)
    {
        printf("Too many arguments!\n");
        return 1;
    }

    string KEY = args[1];

    // Check the length of the key
    if (strlen(KEY) != 26)
    {
        printf("The key should be 26 characters long!\n");
        return 1;
    }

    // Check if all chars are alphabetic
    for (int k = 0; k < 26; k++)
    {
        if (!isalpha(KEY[k]))
        {
            printf("All chars in the key should be alphabetic!\n");
            return 1;
        }
    }

    //Check if all chars are unique
    for (int k = 0; k < 25; k++)
    {
        for (int l = k + 1; l < 26; l++)
        {
            if (KEY[l] == KEY[k])
            {
                printf("All chars in the key should be unique!\n");
                return 1;
            }
        }
    }

    // Convert the key to UPPERCASE
    for (int k = 0; k < 26; k++)
    {
        if (islower(KEY[k]))
        {
            KEY[k] = toupper(KEY[k]);
        }
    }

    // // Convert the key to lowercase
    // string lKEY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // // string key = KEY;
    // printf("KEY length: %i\nlKEY length: %i\n", (int)strlen(KEY), (int)strlen(lKEY));

    // for (int k = 0; k < 26; k++)
    // {
    //   lKEY[k] = tolower(lKEY[k]);
    // }


    // Input a string to encript
    string input = get_string("plaintext: ");

    // Encription
    string output = input;
    for (int k = 0; k < strlen(input); k++)
    {
        if (islower(input[k]))
        {
            output[k] = KEY[input[k] - 97] + 32;
        }

        if (isupper(input[k]))
        {
            output[k] = KEY[input[k] - 65];
        }
    }

    // Output
    printf("ciphertext: %s\n", output);

    return 0;
}