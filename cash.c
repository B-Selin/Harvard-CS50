// aim is to write a code While making change,
// to minimize the number of coins you’re
// dispensing for each customer, lest you run out (or annoy the customer!).
// to minimize numbers of coins due: greedy algorithms.

// a greedy algorithm is one “that always takes the best immediate,
// or local, solution while finding an answer. Greedy algorithms find the overall,
// or globally, optimal solution for some optimization problems,
// but may find less-than-optimal solutions for some instances of other problems.”


// oh ok so I'm not suppose to print out x number of 25 cents y number of 10 cents etc.
// Prompt user for an amount of change
// Use the largest coins possible keeping track of coins used
// print the number of coins

int main(void)
{
// first ask for the amount of change in float. Should I assume code has to accept change
//between 0.00 and 0.99? Nope, test said it failed with the output for 1.6, soooo sky is the limit.
	float i;
    do
    {
	    i = get_float("Change owed: ");

    }
    while (0.00 >=  i);

    int cents = round(i * 100);

    int change = 0;

// keep track of remaining change and how many coins used
    while (25 <= cents)
    {
        cents = cents - 25;
        change ++;
    }

    while (10 <= cents)
    {
        cents = cents - 10;
        change ++;
    }

    while (5 <= cents)
    {
        cents = cents - 5;
        change ++;
    }

    while (1 <= cents)
    {
        cents = cents - 1;
        change ++;
    }

    printf("%i\n", change);


}


//this is not as clean as I want, I may come back after I finish the credit part
