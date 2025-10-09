import java.util.LinkedHashMap;
import java.util.Map;

/**
 * Problem: Find the First Non-Repeated Character in a String
 *
 * Given a string, the task is to find the first character that does not repeat.
 *
 * Examples:
 * Input: "swiss"
 * Output: "First non-repeated character: w"
 *
 * Input: "hello"
 * Output: "First non-repeated character: h"
 *
 * Approach:
 * 1. Use a LinkedHashMap to store the frequency of each character.
 *    - Key: Character
 *    - Value: Count of occurrences
 * 2. LinkedHashMap maintains the insertion order, unlike HashMap.
 *    This ensures we check characters in the order they appear.
 * 3. Iterate through the string and populate the map with counts.
 * 4. Iterate through the map entries:
 *    - The first character with a count of 1 is the answer.
 *
 * Time Complexity: O(n) 
 * Space Complexity: O(n)
 */
public class FirstNonRepeatedChar {

    public static void main(String[] args) {

        // Test cases
        String[] testStrings = {"swiss", "hello", "aabbcc", "programming"};

        for (String s : testStrings) {
            System.out.println("Input: " + s);
            System.out.println("Output: " + firstNonRepeated(s));
            System.out.println("-------------------------");
        }
    }

    /**
     * Finds the first non-repeated character in the string
     * @param str input string
     * @return first non-repeated character as a String, or message if none found
     */
    public static String firstNonRepeated(String str) {
        LinkedHashMap<Character, Integer> charCountMap = new LinkedHashMap<>();

        // Count frequency of each character
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            charCountMap.put(ch, charCountMap.getOrDefault(ch, 0) + 1);
        }

        // Find the first character with count 1
        for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
            if (entry.getValue() == 1) {
                return "First non-repeated character: " + entry.getKey();
            }
        }

        return "No non-repeated character found";
    }
}
