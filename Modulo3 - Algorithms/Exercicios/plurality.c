#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name)
{
    int i = 0;
    while (i < candidate_count)
    {
        int c = 0;
        int n = strlen(name);
        while (c < n)
        {
            if (candidates[i].name[c] != name[c])
            {
                break;
            }

            if (candidates[i].name[c] == name[c] && n == c + 1 && candidates[i].name[c + 1] == '\0')
            {
                candidates[i].votes++;
                return true;
            }
            c++;
        }
        i++;
    }
    return false;
}

void print_winner(void)
{
    int i = 0;
    int votes = 0;

    while (i < candidate_count)
    {
        if (votes < candidates[i].votes)
        {
            votes = candidates[i].votes;
        }
        i++;
    }
    i = 0;
    while (i < candidate_count)
    {
        if (votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
        i++;
    }
}

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

    int i = 0;
    while (i < candidate_count)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        i++;
    }
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    i = 0;
    while (i < voter_count)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        i++;
    }

    // Display winner of election
    print_winner();
    return 0;
}

