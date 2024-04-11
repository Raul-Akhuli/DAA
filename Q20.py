def tsp(distances):
    """Solve the TSP using dynamic programming.

    Args:
        distances: A 2D array of distances between cities.

    Returns:
        The shortest tour.
    """

    # Create a 2D array to store the minimum distances.
    dp = [[float('inf')] * (1 << len(distances)) for _ in range(len(distances))]

    # Initialize the minimum distance to reach the starting city.
    for i in range(len(distances)):
        dp[i][1 << i] = 0

    # Iterate through all subsets of cities.
    for subset in range(1, 1 << len(distances)):
        for current_city in range(len(distances)):
            # Check if the current city is in the subset.
            if subset & (1 << current_city):
                for prev_city in range(len(distances)):
                    # Check if the previous city is in the subset and is not the same as the current city.
                    if prev_city != current_city and subset & (1 << prev_city):
                        # Calculate the minimum distance to reach the current city from the subset.
                        dp[current_city][subset] = min(
                            dp[current_city][subset],
                            dp[prev_city][subset ^ (1 << current_city)] + distances[prev_city][current_city]
                        )

    # Return the shortest tour.
    return min(dp[i][(1 << len(distances)) - 1] for i in range(len(distances)))


distances = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

tour = tsp(distances)

print(tour)
