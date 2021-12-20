

//Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks,
//Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller
//than they are wide.

//the gap between hash is two spaces wide
//one solution, printing a function, (i.e. n line long) gives you (n-1) spaces n hash, 2 spaces and so on?


int main(void)
{
	int i;
do
{
	i = get_int("Height: ");

}
while (1 >  i || i > 8);

//this initial loop below might be the missing part, I keep declaring the space and the hast,
//but it constantly gives the same result.

// so, x variable is for number of rows
for (int x = 0; x < i; x++)

{
//h for hash, s for space
// keep following loops seperate, they are not suppose to be nested under each other

// "h" is for blanks, so starting from "number or row + 1" , finish at i

	for (int h = x + 1; h < i; h++)
	{
		printf(" ");
	}


// number of spaces, starting from number of raws and initial i
	for (int s = i + x + 1 ; s > i; s--)
	{
		printf("#");

	}
	printf("  ");
		for (int s = i + x + 1 ; s > i; s--)
	{
		printf("#");

	}

		for (int h = x + 1; h < i; h++)
	{
		printf(" ");

	}

	printf("\n");

	}


}

//I used the hash and space loop twice, cause honestly don't know how else I can do this
