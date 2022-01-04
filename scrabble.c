#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// idea: get two words, turn the chars of those words into uppercase and do a "minus A" in ascii. this should give the place of that char in alphabet.
// then we can match the points array and the char.
// then we can add the points.
// sounds good on paper :p

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    for (int i = 0, n = strlen(word1); i < n; i++)
    {
        if (islower(word1[i]))
        {
            printf("%c", toupper(word1[i]));
        }
        else
        {
            printf("%c", word1[i]);
        }
    }
    for (int i = 0, n = strlen(word2); i < n; i++)
    {
        if (islower(word2[i]))
        {
            printf("%c", toupper(word2[i]));
        }
        else
        {
            printf("%c", word2[i]);
        }
    }
    printf("\n");
    // Score both words
    // ok so what I dont get is why do we score before "compute_score" function

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins.\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins.\n");
    }
    else
    {
        printf("Tie.\n");
    }
}

int compute_score(string word)

{
    //score starts at 0, then do the minus A thing, aaand apparently in order to do this, I dont have to deal with ascii eq. cause'A' works as it is
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if(isupper(word[i]))
        {
            score+= POINTS[word[i]-'A'];
        }
        //no need to turn everything to capital, tiny small a does the same
        else if (islower(word[i]))
        {
            score+= POINTS[word[i]-'a'];
        }
    }
    return score;
}