#include <stdio.h>

// Function to perform binary search on a 2D array stored in row-major order
int binarySearch2D(int A[], int rows, int cols, int target) {
    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midValue = A[mid];

        // Convert 1D index to 2D indices
        int row = mid / cols;
        int col = mid % cols;

        if (midValue == target) {
            return 1; // Element found
        } else if (midValue < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0; // Element not found
}

int main() {
    int rows = 3;
    int cols = 4;
    int A[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 3;

    if (binarySearch2D((int *)A, rows, cols, target)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}
