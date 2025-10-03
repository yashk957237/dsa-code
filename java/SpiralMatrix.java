// https://leetcode.com/problems/spiral-matrix-ii/

import java.util.*;

public class SpiralMatrix {
    public static void main(String[] args) {
        int n = 5;
        int[][] ans = generateMatrix(n);
        // Properly print the 2D array
        for (int[] an : ans) {
            System.out.println(Arrays.toString(an));
        }
    }
    static int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int value = 1;

        int colStart = 0, colEnd = n - 1, rowStart = 0, rowEnd = n - 1;

        while (colStart <= colEnd && rowStart <= rowEnd) {
            // Left to Right
            for (int i = colStart; i <= colEnd; i++) {
                result[rowStart][i] = value++;
            }
            rowStart++;
            // Up to Down
            for (int j = rowStart; j <= rowEnd; j++) {
                result[j][colEnd] = value++;
            }
            colEnd--;
            // Right to Left
            if (rowStart <= rowEnd) {
                for (int k = colEnd; k >= colStart; k--) {
                    result[rowEnd][k] = value++;
                }
            }
            rowEnd--;
            //Down to Up
            if (colStart <= colEnd) {
                for (int l = rowEnd; l >= rowStart; l--) {
                    result[l][colStart] = value++;
                }
            }
            colStart++;
        }

        return result;
    }
}