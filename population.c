int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Start size: ");
    }

    while (n < 9);

    // TODO: Prompt for end size

    int x;
    do
    {
        x = get_int("End size: ");
    }

    while (x < n);


    // TODO: Calculate number of years until we reach threshold
    //Note to self: I forgot to calculate the cumulative initial value. I need to find a way to create a loop that continues adding 1/3rd and reducing 1/4th

    //create a count variable? checked some s.o. pages, this might work
    int count = 0;
   
    while (n < x)
    {
        n = n + n / 3 - n / 4;
        count ++;
    }

    printf("Years: %i\n", count);

}