def merge_sort(arr):
    """
    Sorts an array in ascending order using the Merge Sort algorithm.

    Args:
        arr: A list of comparable elements.

    Returns:
        A new list containing the sorted elements.
    """
    if len(arr) > 1:
        # 1. Find the middle of the array
        mid = len(arr) // 2
        
        # 2. Divide the array into two halves
        left_half = arr[:mid]
        right_half = arr[mid:]

        # 3. Recursively sort both halves
        merge_sort(left_half)
        merge_sort(right_half)

        # 4. Merge the sorted halves
        i = j = k = 0

        # Copy data to temp arrays left_half[] and right_half[]
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Check if any element was left in the left half
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        # Check if any element was left in the right half
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Example usage:
if __name__ == "__main__":
    my_list = [38, 27, 43, 3, 9, 82, 10]
    print(f"Original array: {my_list}")
    
    merge_sort(my_list)
    
    print(f"Sorted array: {my_list}")
