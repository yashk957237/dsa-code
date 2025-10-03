def linear_search(arr, target):
    for index, value in enumerate(arr):  
        if value == target:
            return index  
    return -1  

# Example
numbers = [10, 20, 30, 40, 50]
target = 30