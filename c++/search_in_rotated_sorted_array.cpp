#include <iostream>
#include <vector>
using namespace std;

// Function to search target in a rotated sorted array
int searchInRotatedSortedArray(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the target
        if (nums[mid] == target) return mid;

        // Determine which part is sorted
        if (nums[left] <= nums[mid]) { // Left part is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in left part
            } else {
                left = mid + 1; // Target is in right part
            }
        } else { // Right part is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in right part
            } else {
                right = mid - 1; // Target is in left part
            }
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = searchInRotatedSortedArray(nums, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
