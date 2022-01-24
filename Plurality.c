#include <cs50.h>
#include <stdio.h>
#include <string.h>

//keep track of candidates
//keep track of votes

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct  //you can use to give a type a new name
{
    string name; //represents the name of the candidate
    int votes; //represents the number of votes they get
}
candidate;

// Array of candidates
candidate candidates[MAX]; 

// Number of candidates  representing the number of candidates in the election, copies command-line arguments into the array candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote. Incase we wanted voters given a second chance, we could have used a while loop. But no we want chaos, and people shouldn't allowed to have a second chance if they cant even spell right
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO use strcmpr with a for function like the one we used previous week?
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) //do we want a case sensitive compare or not?
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO count every vote of each candidate, find a max value, compare that max value with each candidates vote?
    int max_vote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes; //defining max vote as highest number of votes
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}