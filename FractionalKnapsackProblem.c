#include <stdio.h>

// --- Bubble Sort function (descending order by ratio) ---
void bubbleSort(float ratio[], float weight[], float profit[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // swap ratio
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                // swap weight
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                // swap profit
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }
}

// --- Knapsack function ---
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i;
    float u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i], tp = tp + (x[i] * profit[i]);

    printf("\nMaximum profit is: %.2f\n", tp);
}

// --- Main function ---
int main() {
    float weight[20], profit[20], capacity, ratio[20];
    int num, i;

    printf("\nEnter the number of objects: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object:\n");
    for (i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // --- Sort using Bubble Sort ---
    bubbleSort(ratio, weight, profit, num);

    // --- Call Knapsack ---
    knapsack(num, weight, profit, capacity);

    return 0;
}
