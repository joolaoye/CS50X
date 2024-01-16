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
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

bool has_path(int source, int target);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
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
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(name, candidates[i]) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int j = 0; j < candidate_count; j++){
        int cur = ranks[j];
        for (int k = j + 1; k < candidate_count; k++){
            int next = ranks[k];
            preferences[cur][next] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++){
        for (int j = i + 1; j < candidate_count; j++){
            if (preferences[i][j] != preferences[j][i]){

                pair new;

                if (preferences[i][j] > preferences[j][i]){
                    new.winner = i;
                    new.loser = j;
                }

                else{
                    new.winner = j;
                    new.loser = i;
                }

                pairs[pair_count] = new;
                pair_count += 1;
            }

        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 1; i < pair_count; i++){
        int j = i - 1;

        pair current = pairs[i];
        int cur = preferences[current.winner][current.loser] - preferences[current.loser][current.winner];

        while (j >= 0 && (preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner]) < cur){
            pairs[j + 1] = pairs[j];
            j -= 1;
        }

        pairs[j + 1] = current;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++){
        pair cur = pairs[i];
        int row = cur.winner, col = cur.loser;

        if (!has_path(col, row)){
            locked[row][col] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++){
        bool path = false;
        for (int j = 0; j < candidate_count; j++){
            if (has_path(j,i)){
                path = true;
            }
        }

        if (!path){
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

bool has_path(int source, int target){
    if (locked[source][target]){
        return true;
    }

    for (int i = 0; i < candidate_count; i++){
        if (locked[source][i]){
            if (has_path(i,target)){
                return true;
            }
        }
    }

    return false;
}