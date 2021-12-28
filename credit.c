//write a program that prompts the user for a credit card number
//and then reports (via printf) whether it is a valid American Express,
//MasterCard, or Visa card number, per the definitions of each’s format herein.
//So that we can automate some tests of your code, we ask that
//your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n



int main(void)
{
// Ask for credit card number, length shooul be between 13-16 char
    int l;
    char myCard[17];
	long i;
    do
    {
        i = get_long("Number: ");
        sprintf(myCard, "%ld", i);
        l = sprintf(myCard, "%ld", i);
    }
    while (0 >  l || l > 17);


//calculate checksum
//idea here, try to add eevery other number using a loop?
// lets give another int the value of card number
// j is equal to i, oddsum starts at 0

    long j = i;
    int oddSum = 0;
    int remainder1;
    int remainder0;
    while (j != 0)
    {
        remainder1 = 2 * ((j % 100) / 10);
        remainder0 = remainder1 % 10 + round(remainder1 / 10);
        oddSum = oddSum + remainder0 ;
        j = j / 100;
    }
    //sum the rest of the digits
    long k = i;
    int evenSum = 0;
    int remainder2;
    while (k != 0)
    {
        remainder2 = k % 10;
        evenSum = evenSum + remainder2;
        k = k / 100;
    }
    int checksum = oddSum + evenSum;
//check for card length and starting digits
    if (checksum % 10 == 0)
    {
        if ( l == 15)
        {
            if ((i / 10000000000000) == 34 || (i / 10000000000000) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if ( l == 13)
        {
            if ( (i/1000000000000) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //I had a problem with length 16, cause it both works with master and visa, and since visa was before master, mastercard numbers kept returning invalid
        // so I combined master and visa here, instead of checking visa and master seperately, I check them under length 16
        else if ( l == 16)
        {
            if (55 == (i / 100000000000000) || 54 == (i / 100000000000000) || 53 == (i / 100000000000000) || 51 == (i / 100000000000000) || 52 == (i / 100000000000000))
            {
                printf("MASTERCARD\n");
            }

            else if ((i/1000000000000000) == 4 )
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if( 13 > l)
        {
            printf("INVALID\n");
        }
        else if( 17 < l)
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }


//print Amex 15 digit/ mastercard 16 digit/ visa 13 16/ invalid
}