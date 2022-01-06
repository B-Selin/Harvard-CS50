#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



//coleman liau index: index = 0.0588 * L - 0.296 * S - 15.8 where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
// prompt user for text
int main(void)

{
    string word = get_string("Text: ");
    int n = strlen(word);
    //number of letters:
    int l = 0;
    // number on blanks or tabs or anything non character:
    // the chars can be used to seperate words: c == ' ' || c == '\n' || c == '\t'
    // I had some errors because grade level turned out to be less than it is suppose to be, increased the initial number to 1
    int b = 1;
    // sentences, . ? and ! :
    int s = 0;
    int count_letters(string text);
    {
        for (int i = 0; i < n; i++)
        {
            if (isalpha(word[i])) //letter
            {
                l ++;
                //printf("%i\n", l);
            }

            else if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t') //word
            {
                b ++;
                //printf("%i\n", b);
            }
            else if (word[i] == '.' || word[i] == '?' || word[i] == '!') // sentence
            {
                s ++;
                //printf("%i\n", s);
            }
        }

        float equation = (0.0588 * l / b * 100) - (0.296 * s / b * 100) - 15.8;
        int index = round(equation);
        // 1 and 16 is different, if less than 1, "Before Grade 1", if greater than 16, (Grade 16+)
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }


    }



}
