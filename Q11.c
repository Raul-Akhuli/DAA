// C program to find median of an array
#include <stdio.h>
#include <stdlib.h>

int a, b;

// Returns the correct position of pivot element
int Partition(int arr[], int l, int r) {
    int lst = arr[r];
    int i = l;
    int j = l;
    while (j < r) {
        if (arr[j] < lst) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

// Picks a random pivot element between l and r and partitions arr[l..r] around the randomly picked element using partition()
int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    int temp = arr[l + pivot];
    arr[l + pivot] = arr[r];
    arr[r] = temp;
    return Partition(arr, l, r);
}

// Utility function to find median
void MedianUtil(int arr[], int l, int r, int k, int a1, int b1) {
    extern int a, b;

    if (l <= r) {
        int partitionIndex = randomPartition(arr, l, r);
        if (partitionIndex == k) {
            b = arr[partitionIndex];
            if (a1 != -1) {
                return;
            }
        } else if (partitionIndex == k - 1) {
            a = arr[partitionIndex];
            if (b1 != -1) {
                return;
            }
        }
        if (partitionIndex >= k) {
            MedianUtil(arr, l, partitionIndex - 1, k, a, b);
        } else {
            MedianUtil(arr, partitionIndex + 1, r, k, a, b);
        }
    }
}

// Function to find Median
void findMedian(int arr[], int n) {
    extern int a, b;
    a = -1;
    b = -1;

    if (n % 2 == 1) {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        int ans = b;
        printf("Median = %d\n", ans);
    } else {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        int ans = (a + b) / 2;
        printf("Median = %d\n", ans);
    }
}

// Driver code
int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMedian(arr, n);
    return 0;
}
