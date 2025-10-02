def bubble_sort(arr):
    """
    Bubble sort algorithm implementation
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    n = len(arr)
    
    for i in range(n):
        # Flag to optimize - if no swapping occurs, array is sorted
        swapped = False
        
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        # If no swapping occurred, array is already sorted
        if not swapped:
            break
    
    return arr

# Test the function
if __name__ == "__main__":
    numbers = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {numbers}")
    
    sorted_numbers = bubble_sort(numbers.copy())
    print(f"Sorted array: {sorted_numbers}")