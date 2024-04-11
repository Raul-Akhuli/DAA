// Function to get the second smallest and second largest elements in an array
void getElements(int arr[], int n) {
    if (n == 0 || n == 1) {
        printf("-1 -1\n");  // edge case when only one element is present in array
    }
    // Sorting the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int small = arr[1];
    int large = arr[n - 2];
    printf("Second smallest is %d\n", small);
    printf("Second largest is %d\n", large);
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
