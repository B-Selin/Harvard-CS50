#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates, definin two constants here, one is max voters one is max candidates

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
// this is two dimensional array preference. max-voter is [i], and given candidate is that voters' [j]th preference

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated; //that indicates whether the candidate has been eliminated from the election.
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES]; //What is the point of this line. ASK MARC. We created that struck "candidate" and now we are creating an array named "candidates", where max i can be max_candidates?

// Numbers of voters and candidates
//we are saying voter count and candidate counts are integers. Cool
int voter_count;
int candidate_count;

// Function prototypes, left to me to complete

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++) // is this 4? it seems like to be the 4th loop under main
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            // is this like, every voter has to rank and give names of every candidate? ith voter get_sting aka candidate name for wank 1 and then 2 then 3 etc.

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4; // WTF is return 4, what is 4?
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // check for every number of candidates
    {
        if (strcmp(candidates[i].name, name) == 0) //compare name.
        {
            preferences[voter][rank] = i;
            //Recall that preferences[i][j] stores the index of the candidate who is the jth ranked preference for the ith voter. So if we have a matching name, we should update the preferences array with the value of i
            return true;
            // I assume every voter has to rank every candidate right? So since i iterates through the candidate count, we should update the voter's rank for that name to i ?
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
//Step one, iterate through number of voters
//step 2, iterate through number of candidates
//so there is a list created before, by harvard guys (thank god) and it has eliminated candidate names
//"Recall that the candidate struct has a field called eliminated, which will be true if the candidate has been eliminated from the election."
//break if the voters[i] candidate [j] is in that eliminated list?
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++) // iterate through every voter
    {
        for (int j = 0; j < candidate_count; j++) // iterate through every candidate
        {
            if (!candidates[preferences[i][j]].eliminated)
                // check if jth cand of ith voter is on the eliminated list. eliminated was a bool so true or false
            {
                // Oh ok so pref.votes ++ check line 58
                candidates[preferences[i][j]].votes ++;
                break; // SEMICOLON!!
            }
        }
    }
    // TODO
    return;
}

// Print the winner of the election, if there is one
//i will have to check every candidates vote count to see if they are bigger or equal to max votes / 2 +1
//or vote count is bigger than max votes / 2
//"Recall that voter_count stores the number of voters in the election"

bool print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // iterate through every candidate and check if they have more votes than half
    {
        if (candidates[i].votes > voter_count / 2) // can I do math inside if?
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = MAX_VOTERS; // cs50 discussion board
    // I get an error when cads are tied it fails to identify correct min
    for (int i = 0; i < candidate_count; i++) //iterate through every candidate
    {
        if (candidates[i].eliminated == false)
            //if İth candidate is not in the eliminated list (the bool value was true before, I changed it so now the error seems to be gone, but who knows :p)
        {
            if (candidates[i].votes < min) //check if the candidates vote is kess than min. if so, make min equal to that vote count
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) //iterate through every candidate
    {
        if (candidates[i].eliminated == false) //if that candidate is not eliminated
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) //iterate through every candidate
    {
        if (candidates[i].votes == min)
            //instead of if not eliminated then continue doing somethin gsomething, now we will go with if minimum then go move into eliminated
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}