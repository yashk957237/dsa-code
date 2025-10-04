def insertion_sort(arr):
    """
    Insertion sort algorithm implementation
    Time Complexity: O(n²) worst case, O(n) best case
    Space Complexity: O(1)
    """
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        # Move elements that are greater than key one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key
    
    return arr

def insertion_sort_with_steps(arr):
    """
    Insertion sort with step visualization
    """
    steps = [arr.copy()]
    
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key
        steps.append(arr.copy())
    
    return arr, steps

def binary_insertion_sort(arr):
    """
    Optimized insertion sort using binary search
    Time Complexity: O(n²) but with fewer comparisons
    Space Complexity: O(1)
    """
    def binary_search(arr, val, start, end):
        """Binary search to find insertion position"""
        if start == end:
            return start if arr[start] > val else start + 1
        
        if start > end:
            return start
        
        mid = (start + end) // 2
        
        if arr[mid] < val:
            return binary_search(arr, val, mid + 1, end)
        elif arr[mid] > val:
            return binary_search(arr, val, start, mid - 1)
        else:
            return mid
    
    for i in range(1, len(arr)):
        key = arr[i]
        # Find location to insert using binary search
        loc = binary_search(arr, key, 0, i - 1)
        
        # Shift elements and insert
        arr[loc + 1:i + 1] = arr[loc:i]
        arr[loc] = key
    
    return arr

# Test the functions
if __name__ == "__main__":
    # Test basic insertion sort
    numbers = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {numbers}")
    
    sorted_numbers = insertion_sort(numbers.copy())
    print(f"Sorted array: {sorted_numbers}")
    
    # Test insertion sort with steps
    original = [5, 2, 4, 6, 1, 3]
    result, sort_steps = insertion_sort_with_steps(original)
    
    print(f"\nStep-by-step sorting of {[5, 2, 4, 6, 1, 3]}:")
    for i, step in enumerate(sort_steps):
        print(f"Step {i}: {step}")
    
    # Test binary insertion sort
    test_array = [9, 5, 1, 4, 3]
    print(f"\nBinary insertion sort:")
    print(f"Original: {test_array}")
    binary_sorted = binary_insertion_sort(test_array.copy())
    print(f"Sorted: {binary_sorted}")