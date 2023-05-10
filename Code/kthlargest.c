#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);
    int len = pivotIndex - low + 1;

    if (len == k) {
        return arr[pivotIndex];
    } else if (len > k) {
        return quickselect(arr, low, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, high, k - len);
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int kthLargest = quickselect(arr, 0, n - 1, n - k + 1);

    printf("The %dth largest element is: %d\n", k, kthLargest);

    return 0;
}
