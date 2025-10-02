def linear_search(arr, target):
    """
    Linear search algorithm to find target in array
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def linear_search_all_occurrences(arr, target):
    """
    Find all occurrences of target in array
    Time Complexity: O(n)
    Space Complexity: O(k) where k is number of occurrences
    """
    indices = []
    for i in range(len(arr)):
        if arr[i] == target:
            indices.append(i)
    return indices

def linear_search_with_count(arr, target):
    """
    Linear search that returns index and count of comparisons
    """
    comparisons = 0
    for i in range(len(arr)):
        comparisons += 1
        if arr[i] == target:
            return i, comparisons
    return -1, comparisons

# Test the functions
if __name__ == "__main__":
    test_array = [3, 7, 1, 9, 4, 7, 2, 7, 5]
    search_target = 7
    
    # Basic linear search
    result = linear_search(test_array, search_target)
    print(f"Array: {test_array}")
    print(f"Searching for: {search_target}")
    
    if result != -1:
        print(f"First occurrence found at index: {result}")
    else:
        print("Target not found")
    
    # Find all occurrences
    all_indices = linear_search_all_occurrences(test_array, search_target)
    print(f"All occurrences at indices: {all_indices}")
    
    # Search with comparison count
    index, count = linear_search_with_count(test_array, search_target)
    print(f"Found at index {index} with {count} comparisons")