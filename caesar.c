#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//get key, get plain tect, encipher, print ciphertext

//If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
//If any of the characters of the command-line argument is not a decimal digit, your program should print the message Usage: ./caesar key and return from main a value of 1.
//Recall that printf can print a char using %c.
//Recall that you can explicitly “cast” a char to an int with (char), and an int to a char with (int). Or you can do so implicitly by simply treating one as the other.
// argv stored as stringi to convert it into int, we can use atoi function stored in stdlib.h

int main(int argc, string argv[])
{
    //If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.

    if (argc != 2) //originally I used an "isnumeric" && ==2 in here, but I kept getting non numeric key error. Tried to add "is alpha then print usage" but it resulted in both nonnumeric key and lack of arg error :D So I googled and many people solved it like this
    {
        printf("Usage: ./ceasar k");
        return 1;
    }

    // checking if one of the arguments isalpha (we need an integer) - Looping through the string of integers
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // argv stored as stringi to convert it into int, we can use atoi function stored in stdlib.h
    int k = atoi(argv[1]);// argv[1] is the second thing on that arg

    string plainText = get_string("Plaintext: "); // I cant get to this part, will try to rearrange
    printf("ciphertext: "); // I tried putting this at the end, a mistake, big mistake
    // sooo go with letter by letter
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
    //upper A is 65 and user may enter any kind of numeric values, including something waay more than 26. ın that case we should use a mod 26
        if islower(plainText[i])
        {
            printf("%c", (((plainText[i] + k) - 97) % 26) + 97);
        }
        else if isupper(plainText[i])
        {
            printf("%c", (((plainText[i] + k) - 65) % 26) + 65);
        }
        else
        {
            printf("%c", plainText[i]);
        }
    } // if this little curly thing comes after print, loop breaks at the first letter
    printf("\n");
    return 0;
    //Notice that neither the comma nor the space were “shifted” by the cipher. Only rotate alphabetical characters! (isalpha, isupper, islower and maybe isdigit?)
    //Notice that the case of the original message has been preserved. Lowercase letters remain lowercase, and uppercase letters remain uppercase.

}




//HOW MODULUS WORKS
//code[i] + k = add the key, even an extremely large one
//-97 (or 65 for uppercase) = subtract the "base." This brings the modified value down to a "base" of 0, effectively removing any part of the ASCII system that doesn't apply. It makes the letter "a" or "A" start at 1.
//Now mod by 26. The math here automatically wraps around as many times as required, only returning the "remainder," or offset from the base (which is now 0 thanks to step #2)
//+97 (or 65 for uppercase) = add the "base" back in so that the value can be output correctly in ASCII.