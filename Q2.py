def binary_search(A, key, len):
    low = 0
    high = len - 1

    while low <= high:
        mid = low + ((high - low) // 2)

        if A[mid] == key:
            return mid

        if key < A[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return -1

a = [1, 3, 5, 7, 9, 11, 13, 15, 17, 21]
key = 3

position = binary_search(a, key, len(a))
if position == -1:
    print("Not found")
else:
    print(f"Found it at {position}")

