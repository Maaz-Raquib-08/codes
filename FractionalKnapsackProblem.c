#include <stdio.h>

// --- Merge function ---
void merge(float ratio[], float weight[], float profit[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    float tr[high - low + 1], tw[high - low + 1], tp[high - low + 1];

    // Merge two sorted halves (descending order by ratio)
    while (i <= mid && j <= high) {
        if (ratio[i] >= ratio[j]) {
            tr[k] = ratio[i];
            tw[k] = weight[i];
            tp[k] = profit[i];
            i++;
        } else {
            tr[k] = ratio[j];
            tw[k] = weight[j];
            tp[k] = profit[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tr[k] = ratio[i];
        tw[k] = weight[i];
        tp[k] = profit[i];
        i++; k++;
    }
    while (j <= high) {
        tr[k] = ratio[j];
        tw[k] = weight[j];
        tp[k] = profit[j];
        j++; k++;
    }

    // Copy back to original arrays
    for (i = low, k = 0; i <= high; i++, k++) {
        ratio[i] = tr[k];
        weight[i] = tw[k];
        profit[i] = tp[k];
    }
}

// --- Merge Sort recursive function ---
void mergeSort(float ratio[], float weight[], float profit[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(ratio, weight, profit, low, mid);
        mergeSort(ratio, weight, profit, mid + 1, high);
        merge(ratio, weight, profit, low, mid, high);
    }
}

// --- Knapsack function ---
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, u;
    u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    printf("\nMaximum profit is: %f", tp);
}

// --- Main function ---
int main() {
    float weight[20], profit[20], capacity;
    int num, i;
    float ratio[20];

    printf("\nEnter the no. of objects: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object: ");
    for (i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // --- Sort using Merge Sort ---
    mergeSort(ratio, weight, profit, 0, num - 1);

    // --- Call Knapsack ---
    knapsack(num, weight, profit, capacity);

    return 0;
}
