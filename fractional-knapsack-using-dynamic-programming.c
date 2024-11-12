#include <stdio.h>

// Function to get the maximum of two values
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem using Dynamic Programming
void knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1]; // DP table to store the maximum profit for each subproblem

    // Build the DP table K[][] in bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0; // Base case: 0 items or 0 capacity
            else if (wt[i - 1] <= w)
                // Include the item or exclude it, pick the maximum value
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                // If the item can't be included, exclude it
                K[i][w] = K[i - 1][w];
        }
    }

    // The last entry in the DP table contains the maximum profit
    printf("Maximum profit is %d\n", K[n][W]);

    // To find the selected items:
    printf("Selected items (weights): ");
    w = W;
    for (i = n; i > 0 && w > 0; i--)
    {
        if (K[i][w] != K[i - 1][w])
        {
            printf("%d ", wt[i - 1]);
            w -= wt[i - 1]; // Reduce the remaining capacity
        }
    }
    printf("\n");
}

int main()
{
    int n, W;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    // Input the values (profits) and weights of each item
    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Solve the problem using Dynamic Programming
    knapsack(W, wt, val, n);

    return 0;
}
