#include <stdio.h>

// Function to sort items based on their value-to-weight ratio in descending order
void sortItems(float weight[], float profit[], float ratio[], int n) {
    float temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weights
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
}

void knapsackGreedy(float weight[], float profit[], int n, float capacity) {
    float ratio[50], totalProfit = 0.0, amount;
    
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on ratio (profit per weight unit)
    sortItems(weight, profit, ratio, n);

    // Greedily pick items to maximize profit
    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];  // Take the whole item
            totalProfit += profit[i];
        } else {
            // Take fraction of the remaining item
            amount = (capacity / weight[i]) * profit[i];
            totalProfit += amount;
            break;
        }
    }

    // Output the maximum profit
    printf("Maximum profit that can be obtained: %.2f\n", totalProfit);
}

int main() {
    int n;
    float weight[50], profit[50], capacity;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the weights and profits of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Solve the problem using the greedy approach
    knapsackGreedy(weight, profit, n, capacity);

    return 0;
}
