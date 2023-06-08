#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Verify usage
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
    int i = 0;
    while (i < candidate_count)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
        i++;
    }

    // Number of voters
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Rank vote
    i = 0;
    while (i < voter_count)
    {
        // Query for each rank
        int j = 0;
        while (j < candidate_count)
        {
            char name[50];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

            // Check for invalid vote
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                j--;
            }
            j++;
        }
        i++;
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
            i = 0;
            while (i < candidate_count)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
                i++;
            }
            break;
        }
        eliminate(min);

        // Reset vote counts back to zero
        i = 0;
        while (i < candidate_count)
        {
            candidates[i].votes = 0;
            i++;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Main is iterating through each voter and vote
    // Here we only need to check if vote is valid
    int c = 0;
    while (c < candidate_count)
    {
        if (strcmp(name, candidates[c].name) == 0)
        {
            // When valid record in preferences array
            preferences[voter][rank] = c;
            return true;
        }
        c++;
    }
    return false;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // This loop counts the votes for each session of the election
    // if vote was eliminated, it skips to next preference of that voter
    int v = 0;
    while (v < voter_count)
    {
        int r = 0;
        while (r < candidate_count)
        {
            int c = preferences[v][r];
            if (candidates[c].eliminated == false)
            {
                candidates[c].votes++;
                break;
            }
            r++;
        }
        v++;
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Check each candidate for 50%+ of votes
    int c = 0;
    while (c < candidate_count)
    {
        if (candidates[c].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[c].name);
            return true;
        }
        c++;
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int voteCount = voter_count;
    int c = 0;
    while (c < candidate_count)
    {
        if (candidates[c].votes < voteCount && candidates[c].eliminated == false)
        {
            voteCount = candidates[c].votes;
        }
        c++;
    }
    return voteCount;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // If the same number is running and have the min vote count, it's a tie
    int tieCount = 0;
    int onRun = 0;
    int c = 0;
    while (c < candidate_count)
    {
        // when running and with min vote count add to both counters
        if (candidates[c].eliminated == false && candidates[c].votes == min)
        {
            tieCount++;
            onRun++;
        }
        // When running with more votes add only to running count
        else if (candidates[c].eliminated == false)
        {
            onRun++;
        }
        c++;
    }
    // Checks for tie
    if (tieCount == onRun)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Simple iteration eliminating all that have min vote count
    int c = 0;
    while (c < candidate_count)
    {
        if (candidates[c].eliminated == false && candidates[c].votes == min)
        {
            candidates[c].eliminated = true;
        }
        c++;
    }
}

