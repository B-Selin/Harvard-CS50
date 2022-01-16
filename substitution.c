#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//get key, get plain tect, encipher, print ciphertext
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int repeat = 0;
int main(int argc, string argv[])
{
    //now argc has to be non numeric, uppercase
    //I can copy part of the code from caesar.c
    //again we are looking for 2 args

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int n = strlen(argv[1]);

        if (n == 26) // Now have to check if all characters exist only once, if not then break? I will define the whole alphabet as a string maybe I will use that
            // this is not working and I'm tired. I came up with the idea summing the ascii values of both alphabet and arg, and see if they match. But first sleep I really dont know why I cant use string sort, it would fix all my problems.
            //Couldnt sleep :p Ok when I checked the walkthroughs, I didnt understand how people solve it, so I read a billions code. Sortstring seemed like a very neat solution but it is not working in cs50 libraries? So I watched a billion more things on how to check duplicity. and now I understand how it is working
            // for every letter in the key (variable is j) check if that letter occures one more time in the rest of the string (lets say k) check toupper(arg[1](j)) == toupper(arg[1][k])
        {
            for (int j = 0; j < n ; j++) // checking each element of string
            {
                if (!isalpha(argv[1][j])) // if arg is alphabetic, check the lengt, has to be 26 letters
                    //Failed at "handles invalid characters in key" :/ if numeric value is on the beginning, it reprompts user, but it doesnt to that when number is at the end. so I moved it from line 26 too here
                {
                    printf("Usage: ./substitution key\n");;
                    return 1;
                }
                for (int k = j + 1; k < n; k++)
                {
                    if (toupper(argv[1][j]) == toupper(argv[1][k]))
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
                }
            }
            string plaintext = get_string("plaintext: "); //I tried a billion lines, I hope this is the correct place for this lol
            printf("ciphertext: ");
            int pL = strlen(plaintext);
            for (int i = 0; i < pL; i++)
            {
                if (isupper(plaintext[i])) //change every upper character with upper case ofargv1
                {
                    printf("%c", toupper(argv[1][plaintext[i] - 65]));
                }
                else if (islower(plaintext[i]))
                {
                    printf("%c", tolower(argv[1][plaintext[i] - 97]));
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

// ok now the "supposedly" errory keys give error, and correct key continues with plantext. I have to find a way to replace plaintext with corresponding letter
}