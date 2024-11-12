#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[20], count;

int main()
{
    int n;
    void queen(int row, int n);

    printf(" - N Queens Problem Using Backtracking -\n");
    printf("\nEnter number of Queens: ");
    scanf("%d", &n);

    queen(1, n);
    return 0;
}

// Function for printing the solution
void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);

    for (i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ"); // Queen at i,j position
            else
                printf("\t-"); // Empty slot
        }
    }
}

// Function to check conflicts
// If no conflict for desired position, returns 1; otherwise, returns 0
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        // Checking column and diagonal conflicts
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1; // No conflicts
}

// Function to check for proper positioning of queen
void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column; // No conflicts, so place queen
            if (row == n)
                print(n); // Printing the board configuration
            else
                queen(row + 1, n); // Try queen with next position
        }
    }
}
