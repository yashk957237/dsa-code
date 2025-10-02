def selection_sort(arr):
    """
    Selection sort algorithm implementation
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    n = len(arr)
    
    for i in range(n):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr

def selection_sort_with_steps(arr):
    """
    Selection sort with step-by-step visualization
    """
    n = len(arr)
    steps = []
    
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap and record step
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        steps.append(arr.copy())
    
    return arr, steps

# Test the function
if __name__ == "__main__":
    numbers = [64, 25, 12, 22, 11]
    print(f"Original array: {numbers}")
    
    # Basic selection sort
    sorted_numbers = selection_sort(numbers.copy())
    print(f"Sorted array: {sorted_numbers}")
    
    # Selection sort with steps
    original = [64, 25, 12, 22, 11]
    result, sort_steps = selection_sort_with_steps(original)
    
    print("\nSorting steps:")
    for i, step in enumerate(sort_steps):
        print(f"Step {i + 1}: {step}")