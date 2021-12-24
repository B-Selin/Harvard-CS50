//write a program that prompts the user for a credit card number
//and then reports (via printf) whether it is a valid American Express,
//MasterCard, or Visa card number, per the definitions of each’s format herein.
//So that we can automate some tests of your code, we ask that
//your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n


int main(void)
{
// Ask for credit card number, not sure if I should check the lenght or the sum first.
	long i;
    do
    {
	    i = get_long("Number: ");
	    char cardNumber[17];
	    sprintf(cardNumber, "%ld", i);
    }
    while (12 >  i || i > 17);

    printf("%f\n", cardNumber);


//calculate checksum

//check for card length and starting digits

//print Amex / mastercard/ Cisa/ invalid
}