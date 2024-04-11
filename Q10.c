// C program for implementation of Radix Sort
#include <stdio.h>

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countingSort(int arr[], int n, int exp1) {
    int output[n]; // The output array elements that will have sorted arr
    int count[10] = {0}; // initialize count array as 0

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        int index = arr[i] / exp1;
        count[index % 10]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    int i = n - 1;
    while (i >= 0) {
        int index = arr[i] / exp1;
        output[count[index % 10] - 1] = arr[i];
        count[index % 10]--;
        i--;
    }

    // Copying the output array to arr[],
    // so that arr now contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Method to do Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max1 = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    int exp = 1;
    while (max1 / exp >= 1) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Driver code
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
