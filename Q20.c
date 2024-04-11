
#include <stdio.h>
#include <limits.h>
#include <math.h>

int tsp(int distances[][4], int n) {
    // Create a 2D array to store the minimum distances.
    int dp[n][(1 << n)];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = INT_MAX;
        }
    }

    // Initialize the minimum distance to reach the starting city.
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 0;
    }

    // Iterate through all subsets of cities.
    for (int subset = 1; subset < (1 << n); subset++) {
        for (int current_city = 0; current_city < n; current_city++) {
            // Check if the current city is in the subset.
            if (subset & (1 << current_city)) {
                for (int prev_city = 0; prev_city < n; prev_city++) {
                    // Check if the previous city is in the subset and is not the same as the current city.
                    if (prev_city != current_city && (subset & (1 << prev_city))) {
                        // Calculate the minimum distance to reach the current city from the subset.
                        dp[current_city][subset] = fmin(dp[current_city][subset], dp[prev_city][subset ^ (1 << current_city)] + distances[prev_city][current_city]);
                    }
                }
            }
        }
    }

    // Return the shortest tour.
    int min_tour = INT_MAX;
    for (int i = 0; i < n; i++) {
        min_tour = fmin(min_tour, dp[i][(1 << n) - 1]);
    }
    return min_tour;
}

int main() {
    int distances[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int tour = tsp(distances, 4);
    printf("%d\n", tour);

    return 0;
}

//This C code translates the given Python code for solving the Traveling Salesman Problem (TSP) using dynamic programming. The `tsp` function takes a 2D array of distances between cities and the number of cities `n`. It creates a 2D array `dp` to store the minimum distances between subsets of cities. The function initializes the minimum distance to reach the starting city for each city. It then iterates through all subsets of cities and calculates the minimum distance to reach each city from the subset using dynamic programming. Finally, it returns the minimum tour length by finding the minimum value in the last row of the `dp` array.

//The `main` function initializes the distances array and calls the `tsp` function with the distances and the number of cities. It then prints the resulting tour length.

