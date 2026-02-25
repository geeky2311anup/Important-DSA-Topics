class Solution {

    // Function to count number of set bits (1s) in binary representation of n
    public int countSetBit(int n){
        int count = 0;

        // Keep checking last bit until number becomes 0
        while(n > 0){
            // If last bit is 1, increase count
            if((n & 1) == 1){
                count++;
            }

            // Right shift to check next bit
            n = n >> 1;
        }

        return count;
    }

    /*
        PROBLEM STATEMENT:
        ------------------
        Given an integer array arr, sort the array in ascending order
        by the number of 1's (set bits) in their binary representation.

        If two numbers have the same number of set bits,
        then sort them in ascending numerical order.

        Return the sorted array.
    */

    public int[] sortByBits(int[] arr) {

        int m = arr.length;

        // Convert primitive int[] to Integer[]
        // because Arrays.sort with Comparator works only with objects
        Integer[] num = new Integer[m];

        for(int i = 0; i < m; i++){
            num[i] = arr[i];   // Autoboxing happens here
        }

        // Custom sorting:
        // 1. First compare by number of set bits
        // 2. If equal, compare by actual value
        Arrays.sort(num, (a, b) -> {

            int bitDifference = countSetBit(a) - countSetBit(b);

            // If both numbers have same set bit count
            if(bitDifference == 0){
                return a - b;   // Sort in ascending order
            }
            else{
                return bitDifference; // Sort by set bit count
            }
        });

        // Copy sorted values back into original int array
        for(int i = 0; i < m; i++){
            arr[i] = num[i];
        }

        return arr;
    }
}
