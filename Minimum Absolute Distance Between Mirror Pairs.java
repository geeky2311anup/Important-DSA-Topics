import java.util.*;

class Solution {

    // Reverse digits of a number
    private int reverseNumber(int num) {
        int result = 0;
        int sign = (num < 0) ? -1 : 1;
        num = Math.abs(num);

        while (num != 0) {
            int digit = num % 10;
            result = result * 10 + digit;
            num /= 10;
        }
        return result * sign;
    }

    public int minMirrorPairDistance(int[] arr) {
        Map<Integer, Integer> lastSeen = new HashMap<>();
        int minDist = Integer.MAX_VALUE;

        for (int i = 0; i < arr.length; i++) {
            int revVal = reverseNumber(arr[i]);

            // Check if current value was seen as a reversed number before
            if (lastSeen.containsKey(arr[i])) {
                minDist = Math.min(minDist, i - lastSeen.get(arr[i]));
            }

            // Store reversed value with index
            lastSeen.put(revVal, i);
        }

        return (minDist == Integer.MAX_VALUE) ? -1 : minDist;
    }
}
