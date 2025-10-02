#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * ThreeSum Algorithm Implementation
 * 
 * Problem: Find all unique triplets in an array that sum to zero
 * Time Complexity: O(n²) where n is the length of the array
 * Space Complexity: O(1) excluding the output array
 * 
 * Algorithm:
 * 1. Sort the array to enable two-pointer technique
 * 2. For each element, use two pointers to find pairs that sum to the negative of current element
 * 3. Skip duplicates to ensure unique triplets
 */
class ThreeSumSolver {
public:
    /**
     * Finds all unique triplets that sum to zero
     * @param nums: input array of integers
     * @return: vector of triplets where each triplet sums to zero
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Edge case: array must have at least 3 elements
        if (nums.size() < 3) {
            return result;
        }
        
        // Sort the array to enable two-pointer technique and handle duplicates
        sort(nums.begin(), nums.end());
        
        // Iterate through the array, fixing the first element of triplet
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Two-pointer approach for the remaining two elements
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i]; // We want nums[left] + nums[right] = target
            
            while (left < right) {
                int currentSum = nums[left] + nums[right];
                
                if (currentSum == target) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers
                    left++;
                    right--;
                } else if (currentSum < target) {
                    // Sum is too small, move left pointer right
                    left++;
                } else {
                    // Sum is too large, move right pointer left
                    right--;
                }
            }
        }
        
        return result;
    }
    
    /**
     * Alternative implementation using set for duplicate handling
     * Less efficient but more straightforward for understanding
     */
    vector<vector<int>> threeSumWithSet(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        
        if (nums.size() < 3) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    uniqueTriplets.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
    
    /**
     * Utility function to print the results
     */
    void printTriplets(const vector<vector<int>>& triplets) {
        if (triplets.empty()) {
            cout << "No triplets found that sum to zero." << endl;
            return;
        }
        
        cout << "Found " << triplets.size() << " unique triplet(s):" << endl;
        for (const auto& triplet : triplets) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
        }
    }
};

/**
 * Test function to validate the implementation
 */
void runTests() {
    ThreeSumSolver solver;
    
    cout << "=== ThreeSum Algorithm Test Cases ===" << endl << endl;
    
    // Test Case 1: Standard case with multiple triplets
    cout << "Test Case 1: [-1, 0, 1, 2, -1, -4]" << endl;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solver.threeSum(nums1);
    solver.printTriplets(result1);
    cout << endl;
    
    // Test Case 2: No valid triplets
    cout << "Test Case 2: [1, 2, 3]" << endl;
    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> result2 = solver.threeSum(nums2);
    solver.printTriplets(result2);
    cout << endl;
    
    // Test Case 3: All zeros
    cout << "Test Case 3: [0, 0, 0]" << endl;
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solver.threeSum(nums3);
    solver.printTriplets(result3);
    cout << endl;
    
    // Test Case 4: Empty array
    cout << "Test Case 4: []" << endl;
    vector<int> nums4 = {};
    vector<vector<int>> result4 = solver.threeSum(nums4);
    solver.printTriplets(result4);
    cout << endl;
    
    // Test Case 5: Array with less than 3 elements
    cout << "Test Case 5: [1, 2]" << endl;
    vector<int> nums5 = {1, 2};
    vector<vector<int>> result5 = solver.threeSum(nums5);
    solver.printTriplets(result5);
    cout << endl;
    
    // Test Case 6: Array with duplicates
    cout << "Test Case 6: [-2, 0, 0, 2, 2]" << endl;
    vector<int> nums6 = {-2, 0, 0, 2, 2};
    vector<vector<int>> result6 = solver.threeSum(nums6);
    solver.printTriplets(result6);
    cout << endl;
    
    // Test Case 7: Large array with multiple solutions
    cout << "Test Case 7: [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]" << endl;
    vector<int> nums7 = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    vector<vector<int>> result7 = solver.threeSum(nums7);
    solver.printTriplets(result7);
    cout << endl;
}

int main() {
    cout << "ThreeSum Algorithm Implementation" << endl;
    cout << "=================================" << endl << endl;
    
    // Run comprehensive tests
    runTests();
    
    // Interactive example
    cout << "=== Interactive Example ===" << endl;
    ThreeSumSolver solver;
    
    // Example usage with user input simulation
    vector<int> userInput = {-1, 0, 1, 2, -1, -4};
    cout << "Input array: ";
    for (int i = 0; i < userInput.size(); i++) {
        cout << userInput[i];
        if (i < userInput.size() - 1) cout << ", ";
    }
    cout << endl;
    
    vector<vector<int>> result = solver.threeSum(userInput);
    cout << "Result: ";
    solver.printTriplets(result);
    
    return 0;
}
