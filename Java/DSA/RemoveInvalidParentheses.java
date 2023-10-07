import java.util.*;

/**
 * RemoveInvalidParentheses class solves the problem of removing the minimum number of invalid parentheses
 * from a given string to make it valid. It uses Breadth-First Search (BFS) to explore all possible
 * strings by removing one parenthesis at a time.
 *
 * Problem Statement:
 * Given a string str that contains parentheses and letters, remove the minimum number of invalid
 * parentheses to make the input string valid. Return a list of unique strings that are valid with
 * the minimum number of removals. You may return the answer in any order.
 *
 * Example Test Cases:
 * Input: "()())()", Output: ["(())()","()()()"]
 *
 * @author Rishab Kumar R <a href="https://github.com/Rishab-Kumar-R">GitHub-Rishab-Kumar-R</a>
 */
public class RemoveInvalidParentheses {

    /**
     * Removes the minimum number of invalid parentheses from the given string to make it valid.
     *
     * @param str The input string, only contains "(" and ")".
     * @return Return all possible valid results.
     */
    public List<String> removeInvalidParentheses(String str) {
        List<String> result = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer(str);
        visited.add(str);

        boolean found = false;

        // BFS starts here.
        while (!queue.isEmpty()) {
            String current = queue.poll();

            // If the current string is valid, add it to the result.
            if (isValid(current)) {
                result.add(current);
                found = true;
            }

            // If we already found a valid parentheses pattern, we don't need to do any further bfs.
            if (found) {
                continue;
            }

            // Generate all possible states by removing one "(" or ")".
            for (int i = 0; i < current.length(); i++) {
                if (current.charAt(i) == '(' || current.charAt(i) == ')') {
                    String next = current.substring(0, i) + current.substring(i + 1);
                    if (!visited.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }
                }
            }
        }
        return result;
    }

    /**
     * Checks if a given string has valid parentheses.
     *
     * @param current The input string to check.
     * @return True if the string has valid parentheses, false otherwise.
     */
    private boolean isValid(String current) {
        int count = 0;

        // Count the number of "(" and ")". If count is negative, return false.
        for (char ch : current.toCharArray()) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                // If count is negative, it means there are more ")" than "(".
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }

    /**
     * Main method for testing the RemoveInvalidParentheses class.
     *
     * @param args Command-line arguments (not used).
     */
    public static void main(String[] args) {

        RemoveInvalidParentheses solution = new RemoveInvalidParentheses();

        String str1 = "()())()";
        List<String> result1 = solution.removeInvalidParentheses(str1);
        System.out.println(result1);    // Output: ["(())()","()()()"]

        String str2 = ")(";
        List<String> result2 = solution.removeInvalidParentheses(str2);
        System.out.println(result2);    // Output: [""]

        String str3 = "(a+b)())()";
        List<String> result3 = solution.removeInvalidParentheses(str3);
        System.out.println(result3);    // Output: ["(a+b)()()","(a+b)(())"]

        String str4 = "(((k()((";
        List<String> result4 = solution.removeInvalidParentheses(str4);
        System.out.println(result4);    // Output: ["k()","(k)"]

    }

}
