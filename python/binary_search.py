#author- Seema kumari Patel
#Date - 01 Oct 2025
#Program to implement binary search algorithm in python.

def binary_search(arr, target):
    left = 0, right = len(arr)-1

    while left <= right:
        mid = left + right // 2
        if arr[mid] == target:
            return mid


        elif arr[mid] < target:
            left = mid + 1

        else:
            right = mid - 1

    return -1

if __name__ == '--main__':
    arr = {2, 4, 5, 9, 16, 20, 50, 65, 70}
    target = input("Enter the number as target to be searched:")

    result = binary_search( arr, target)

    if result != -1:
        print("Element found at index:", result)
    else:
        print("Element not found in the array")