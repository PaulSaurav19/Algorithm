#include <stdio.h>

// Function to partition the array around a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    // Loop through the array and move all elements smaller than the pivot to the left
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap the current element with the element at the index i
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at the index i+1 to place it in the correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the index of the pivot element
    return i + 1;
}

// Function to recursively select a pivot and partition the array until the kth largest element is found
int quickselect(int arr[], int low, int high, int k) {
    // If the sub-array contains only one element, return that element
    if (low == high) {
        return arr[low];
    }

    // Partition the array and find the length of the left sub-array
    int pivotIndex = partition(arr, low, high);
    int len = pivotIndex - low + 1;

    // If the length of the left sub-array is equal to k, then the pivot is the kth largest element
    if (len == k) {
        return arr[pivotIndex];
    }
    // If the length of the left sub-array is greater than k, recursively call quickselect on the left sub-array
    else if (len > k) {
        return quickselect(arr, low, pivotIndex - 1, k);
    }
    // If the length of the left sub-array is less than k, recursively call quickselect on the right sub-array
    else {
        return quickselect(arr, pivotIndex + 1, high, k - len);
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Find the kth largest element in the array using quickselect
    int kthLargest = quickselect(arr, 0, n - 1, n - k + 1);

    // Print the kth largest element
    printf("The %dth largest element is: %d\n", k, kthLargest);

    return 0;
}
