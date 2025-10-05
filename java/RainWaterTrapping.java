/**
 * Rain Water Trapping - Two Pointer Approach
 * Calculate total water trapped after raining given elevation heights.
 */
public class RainWaterTrapping {
    
    // Two pointer approach - O(n) time, O(1) space
    public int trap(int[] height) {
        if (height.length == 0) return 0;
        
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
    
    public static void main(String[] args) {
        RainWaterTrapping solution = new RainWaterTrapping();
        
        // Test case 1
        int[] arr1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println("Array: [0,1,0,2,1,0,1,3,2,1,2,1]");
        System.out.println("Water trapped: " + solution.trap(arr1)); // 6
        
        // Test case 2
        int[] arr2 = {4, 2, 0, 3, 2, 5};
        System.out.println("\nArray: [4,2,0,3,2,5]");
        System.out.println("Water trapped: " + solution.trap(arr2)); // 9
        
        // Test case 3
        int[] arr3 = {3, 0, 2, 0, 4};
        System.out.println("\nArray: [3,0,2,0,4]");
        System.out.println("Water trapped: " + solution.trap(arr3)); // 7
    }
}