#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // S calculation of C(MAX/2): Max!/(2!(Max - 2)!)
// pairs is the aaray of all pairs where one candidate is preferred above another

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // S Sets the candidate count to arg count in computer language
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1]; // S matching ith candidate with arg values
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false; // S locked was bool
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1); // S turnes computer rank in to human rank. For every İth voter, ask for candidate names and stores them

            if (!vote(j, name, ranks)) // S if vote doesnt get these 3, retun invalid vote. makes sense. moving on
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    // S aaand run these very simple 3 functions then print winner *facepalm*
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Am I dumb? I just realised int main does all the shit and you can include functions down below. All of my 7 brain cells feel so dumb rn

// Update ranks given a new vote
// I can assume no two candidates have the same name, 3 inputs.
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // iterate through candidates
    {
        if (strcmp(candidates[i], name) == 0) //compare name.
        {
            ranks[rank] = i; //added "choice" at first because I wanted this to be a dfferent word than rank or prefe or candidate, it got confusing.
            //BUT (butt) apparently I'm not suppose to do write just anything I want, it has to be a declared identifier. TIL :p
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) // this is how it goes, voters give a rank to each candidate, so they will be asked just ranks, not candidate order and ranks, just ranks, as in 3-2-4-1
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // iterate through every voter? I guess it has to be voters this time. But it doesnt make sense cause preferences accepts two integer from candidates, not one from voters and one from candidates
    {
        for (int j = i + 1; j < candidate_count; j++) // iterate through every next candidate, like we do in substitution
        {
            preferences[ranks[i]] [ranks[j]] ++; // A huge "ooooh" moment, I got stuck on how to include an expression, like, should I compare int rank[i] and rank[j] etc. I should include them within the brackets. DONT FORGET to put two brackets like this:  preferences[ranks[i]] [ranks[j]], not like this preferences [ranks[i], ranks[j]]
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    //The function should add all pairs of candidates where one candidate is preferred to the pairs array. A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.
    for (int i = 0; i < candidate_count; i++) // iterate through every voter? I guess it has to be voters this time. But it doesnt make sense cause preferences accepts two integer from candidates, not one from voters and one from candidates
    {
        for (int j = i + 1; j < candidate_count; j++) // iterate through every next candidate, like we do in substitution
        {
            if (preferences[i][j] > preferences[j][i]) //if rank of i'th preferance is higher than jth:
            {
                pairs[pair_count].winner = i; // line 24, the identifier is callaed "pairs" not pair
                //pair [i], dunno if i should be i? again we start counting from 0? Wait they mentioned something about this. "The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive)"
                // did pair_count started from 0? Yes check line 68. pair_count = 0. But I don't think I have the abiillty to limit this count-1, the loop does not allowing part itself?
                pairs[pair_count].loser = j;
                // update global var pair_count to the total numner of pairs
                pair_count ++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count ++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}