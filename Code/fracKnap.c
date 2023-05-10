#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item in the knapsack
struct Item {
    int value;  // value of the item
    int weight; // weight of the item
};

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    struct Item* item1 = (struct Item*) a;
    struct Item* item2 = (struct Item*) b;
    double ratio1 = (double) item1->value / item1->weight;
    double ratio2 = (double) item2->value / item2->weight;
    if (ratio1 < ratio2) {
        return 1; // return a positive number if ratio1 is less than ratio2
    } else if (ratio1 > ratio2) {
        return -1; // return a negative number if ratio1 is greater than ratio2
    } else {
        return 0; // return 0 if ratio1 and ratio2 are equal
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(struct Item* items, int n, int capacity) {
    // Sort the items by their value-to-weight ratio in non-increasing order using qsort
    qsort(items, n, sizeof(struct Item), cmp);

    double totalValue = 0.0; // total value of the items in the knapsack
    int remainingCapacity = capacity; // remaining capacity of the knapsack

    for (int i = 0; i < n; i++) {
        // If the item can fit entirely in the knapsack, add its value to the total value and reduce the remaining capacity of the knapsack
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // If the item cannot fit entirely in the knapsack, calculate the fraction of the item that can fit and add its fraction value to the total value
            double fraction = (double) remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50; // capacity of the knapsack
    struct Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int n = sizeof(items) / sizeof(items[0]);

    // Find the maximum total value of items that can be put in the knapsack using the fractional knapsack algorithm
    double maxValue = fractionalKnapsack(items, n, capacity);

    // Print the maximum total value of items that can be put in the knapsack
    printf("The maximum total value of items that can be put in the knapsack is: %lf\n", maxValue);

    return 0;
}
