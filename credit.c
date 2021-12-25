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
    while (12 >  l || l > 17);



//calculate checksum

//check for card length and starting digits

//print Amex / mastercard/ Cisa/ invalid
}