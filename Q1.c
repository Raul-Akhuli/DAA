#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAL 1000000000

// Prints the pair with sum closest to x
void printClosest(int arr[], int n, int x) {
    // To store indexes of result pair
    int res_l, res_r;
    
    // Initialize left and right indexes
    // and difference between
    // pair sum and x
    int l = 0, r = n-1, diff = MAX_VAL;
    
    // While there are elements between l and r
    while (r > l) {
        // Check if this pair is closer than the
        // closest pair so far
        if (abs(arr[l] + arr[r] - x) < diff) {
            res_l = l;
            res_r = r;
            diff = abs(arr[l] + arr[r] - x);
        }
        
        if (arr[l] + arr[r] > x) {
            // If this pair has more sum, move to
            // smaller values.
            r--;
        } else {
            // Move to larger values
            l++;
        }
    }
    
    printf("The closest pair is %d and %d\n", arr[res_l], arr[res_r]);
}

int main() {
    int arr[] = {10, 22, 28, 29, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 54;
    printClosest(arr, n, x);
    return 0;
}

