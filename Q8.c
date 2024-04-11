#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r < l)
		return -1;

	int mid = l + (r - l) / 2;

	// If the element is present at the middle
	// itself
	if (arr[mid] == x)
		return mid;

	// If element is smaller than mid, then
	// it can only be present in the left subarray
	if (arr[mid] > x)
		return binarySearch(arr, l, mid - 1, x);

	// Else the element can only be present
	// in the right subarray
	return binarySearch(arr, mid + 1, r, x);
}

// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
	int ind = binarySearch(arr, 0, n - 1, x);

	// If the element is not present
	if (ind == -1)
		return 0;

	// Count elements on the left side
	int count = 1;
	int left = ind - 1;
	while (left >= 0 && arr[left] == x)
	{
		count++;
		left--;
	}

	// Count elements on the right side
	int right = ind + 1;
	while (right < n && arr[right] == x)
	{
		count++;
		right++;
	}

	return count;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 2;
	printf("%d", countOccurrences(arr, n, x));
	return 0;
}
