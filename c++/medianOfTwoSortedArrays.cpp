/**
 * @file medianOfTwoSortedArrays.cpp
 * @brief Solution to find the median of two sorted arrays in O(log(min(m,n))) time
 * @author Hacktoberfest Contributor
 * @date October 2025
 * 
 * Problem: Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * 
 * Algorithm: Binary Search Approach
 * - Use binary search on the smaller array to find the correct partition
 * - Ensure that elements on the left side are smaller than elements on the right side
 * - The median is calculated based on the maximum of left elements and minimum of right elements
 * 
 * Time Complexity: O(log(min(m, n)))
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the median of two sorted arrays using binary search
     * @param nums1 First sorted array
     * @param nums2 Second sorted array
     * @return The median value as a double
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        // This reduces the search space in binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();  // Size of first array
        int n = nums2.size();  // Size of second array
        int left = 0;          // Left boundary for binary search
        int right = m;         // Right boundary for binary search

        // Binary search to find the correct partition
        while (left <= right) {
            // Partition point for nums1
            int partitionA = (left + right) / 2;
            
            // Partition point for nums2 
            // Total left elements should be (m+n+1)/2
            int partitionB = (m + n + 1) / 2 - partitionA;

            // Find boundary elements around the partition
            // Maximum element on left side of nums1
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            
            // Minimum element on right side of nums1
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            
            // Maximum element on left side of nums2
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            
            // Minimum element on right side of nums2
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            // Check if we found the correct partition
            // All elements on left should be <= all elements on right
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Found the correct partition
                
                // If total elements are even, median is average of middle two elements
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } 
                // If total elements are odd, median is the maximum of left elements
                else {
                    return max(maxLeftA, maxLeftB);
                }
            } 
            // If maxLeftA > minRightB, we need to move left in nums1
            else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } 
            // If maxLeftB > minRightA, we need to move right in nums1
            else {
                left = partitionA + 1;
            }
        }

        // This should never be reached if input arrays are valid
        return 0.0;
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    Solution solution;
    
    // Test case 1: Even total elements
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1 - Arrays: [1,3] and [2]" << endl;
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;
    
    // Test case 2: Odd total elements
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "\nTest 2 - Arrays: [1,2] and [3,4]" << endl;
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}